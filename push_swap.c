/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:16:46 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/10 15:04:23 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_process_raw_args(int argc, char **argv, t_list **stack_a, int *error_flag)
{
	int i;
	int	val;
	t_list	*tmp;

	tmp = NULL;
	i = 1;
	while (i < argc)
	{
		val = ft_atoi(argv[i], error_flag);
		tmp = ft_new_node(val);
		ft_add_back(stack_a, tmp);
		i++;
	}
}

// void	ft_process_split_args(int argc, char **argv, t_stack *stack_a, t_stack *tmp)
// {

// }

// t_stack	*ft_create_stack(int argc, char **argv, t_stack *stack_a, t_stack *tmp)
// {
// 	if (argc >= 2)
// 		ft_process_raw_args(argc, argv, stack_a);
// 	// else if (argc == 2)
// 	// 	ft_process_split_args(argc, argv, stack_a, tmp);
// 	return (stack_a);
// }

int	main(int argc, char **argv)
{
	t_list 	*stack_a;
	int		error_flag;
	// t_list	*stack_b;

	stack_a = NULL;
	// stack_b = NULL;
	
	error_flag = 0;
	ft_process_raw_args(argc, argv, &stack_a, &error_flag);
	if (ft_input_invalid(error_flag) == 1)
		return (1);
	printlist(stack_a);
	
	return (0);
}

