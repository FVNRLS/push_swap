/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:50:31 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/21 18:43:54 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

/*
	Compare the parsed instructions from stdin one by one against the standard.
	If no diff. found 
		-> apply the particular instruction and return EXIT_SUCCESS
	If diff found, then the instruction provided doesn't exist
		->return EXIT_ERROR
*/
static int	ft_apply_instructions(t_list **stack_a, t_list **stack_b, char *op)
{
	if (ft_strncmp(op, "pa\n", 3) == 0)
		ch_pa(stack_a, stack_b);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		ch_pb(stack_a, stack_b);
	else if (ft_strncmp(op, "sa\n", 3) == 0)
		ch_sa(stack_a);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		ch_sb(stack_b);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ch_ss(stack_a, stack_b);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ch_ra(stack_a);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		ch_rb(stack_b);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		ch_rr(stack_a, stack_b);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		ch_rra(stack_a);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		ch_rrb(stack_b);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		ch_rrr(stack_a, stack_b);
	else
		return (EXIT_ERROR);
	return (EXIT_SUCCESS);
}

/*
	Read by 1 byte from stdin and save the result into buffer.
	Check the buffer for '\n'. 
	If newline found 
		-> compare the input with standard instructions.
		If the EXIT_ERROR is returned from ft_apply_instructions()
			-> return EXIT_ERROR
	If return was successful -> continue with the next instruction.
*/
static int	ft_parse_instructions(t_list **stack_a, t_list **stack_b)
{
	int		fd;
	char	*buf;
	int		i;

	fd = STDIN_FILENO;
	buf = ft_calloc(5, sizeof(char));
	i = 0;
	while ((read(fd, &buf[i], 1)) != 0)
	{
		if (ft_nl_found(buf))
		{
			if (ft_apply_instructions(stack_a, stack_b, buf) == EXIT_ERROR)
			{
				ft_free_buf(&buf);
				write(2, "Error\n", 6);
				return (EXIT_ERROR);
			}
			ft_reset_buf(&buf);
			i = 0;
		}
		else
			i++;
	}
	ft_free_buf(&buf);
	return (EXIT_SUCCESS);
}

/*
	Takes as an argument the stack a formatted as a list of integers. 
	If no argument is given, it stops and displays nothing. 
	Waits and reads instructions on the standard input.
	Once all the instructions have been read, executes them on the stack.
	In case of error, displays "Error".
	Error examples: 
		- some arguments are not integers
		- some arguments are bigger than an integer
		- there are duplicates
		- instruction does not exist and/or is incorrectly formatted.
	If in the end the stack is sorted and the stack b is empty, displays "OK".
	Otherwise, displays "KO".
*/
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		res;

	stack_a = NULL;
	stack_b = NULL;
	if (ft_create_stack(argc, argv, &stack_a) == false)
	{
		ft_delete_stack(&stack_a);
		return (EXIT_ERROR);
	}
	res = ft_parse_instructions(&stack_a, &stack_b);
	if (res == EXIT_ERROR)
	{
		ft_delete_stack(&stack_a);
		ft_delete_stack(&stack_b);
		return (EXIT_ERROR);
	}
	if (ft_stack_sorted(stack_a) == true && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_delete_stack(&stack_a);
	ft_delete_stack(&stack_b);
	return (0);
}
