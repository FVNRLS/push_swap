/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:50:31 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/21 14:54:46 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

//TODO: prichesat!

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


//TODO: rewrite free buf
static int	ft_parse_instructions(t_list **stack_a, t_list **stack_b)
{
	int 	fd;
	char	*buf;	
	int		i;
	
	fd = STDIN_FILENO;
	buf = ft_calloc(5, sizeof(char));
	i = 0;
	while ((read(fd, &buf[i], 1)) != 0)
	{
		if (ft_nl_found(buf) == true)
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

int	main(int argc, char **argv)
{
	t_list 	*stack_a;
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

