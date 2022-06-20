/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:50:31 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/20 19:49:06 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

// static int	ft_message_error(void)
// {
// 	write(2, "Error\n", 6);
// 	return (EXIT_FAILURE);
// }

// static int	ft_apply_instructions(t_list *data, char *operation)
// {
// 	if (ft_strncmp(operation, "pa\n", 3) == 0)
// 		pa(data);
// 	else if (ft_strncmp(operation, "pb\n", 3) == 0)
// 		pb(data);
// 	else if (ft_strncmp(operation, "sa\n", 3) == 0)
// 		sa(data);
// 	else if (ft_strncmp(operation, "sb\n", 3) == 0)
// 		sb(data);
// 	else if (ft_strncmp(operation, "ss\n", 3) == 0)
// 		ss(data);
// 	else if (ft_strncmp(operation, "ra\n", 3) == 0)
// 		ra(data);
// 	else if (ft_strncmp(operation, "rb\n", 3) == 0)
// 		rb(data);
// 	else if (ft_strncmp(operation, "rr\n", 3) == 0)
// 		rr(data);
// 	else if (ft_strncmp(operation, "rra\n", 4) == 0)
// 		rra(data);
// 	else if (ft_strncmp(operation, "rrb\n", 4) == 0)
// 		rrb(data);
// 	else if (ft_strncmp(operation, "rrr\n", 4) == 0)
// 		rrr(data);
// 	else
// 		return (EXIT_ERROR);
// 	return (EXIT_SUCCESS);
// }

void	ft_parse_instructions()
{
	int 	fd;
	char	*buf;	
	int		i;
	
	fd = 0;
	buf = ft_calloc(5, sizeof(char));
	i = 0;
	while ((read(fd, &buf[i], 1)) != 0)
	{
		if (ft_nl_found(buf) == true)
		{
			printf("%s", buf);
			// ft_apply_instructions(); //return = EXIT MESSAGE (SUCCESS or ERROR)
			ft_reset_buf(&buf);
			i = 0;
		}
		else
			i++;
	}
	free(buf);
	buf = NULL;
}

int	main(int argc, char **argv)
{
	t_list 	*stack_a;
	t_list	*stack_b;
	int		res;

	
	stack_a = NULL;
	stack_b = NULL;
	res = 0; //
	if (ft_create_stack(argc, argv, &stack_a) == false)
	{
		ft_delete_stack(&stack_a);
		res = EXIT_FAILURE;
	}
	ft_parse_instructions();


	
	// if (stack_a_sorted() && stack_b == NULL)
	// 	write(1, "OK\n", 3);
	// else if (res == EXIT_FAILURE)
	// 	write(1, "KO\n", 3);
	return (0);
}

