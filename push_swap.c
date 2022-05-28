/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:16:46 by rmazurit          #+#    #+#             */
/*   Updated: 2022/05/28 18:02:38 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_process_raw_args(int argc, char **argv, t_list **stack_a)
{
	int i;
	int	val;
	t_list	*tmp;

	tmp = NULL;
	i = 1;
	while (i < argc)
	{
		val = ft_atoi(argv[i]);
		tmp = create_new_node(val);
		// insert_at_head(stack_a, tmp); //TODO: works but in other direction
		ft_lstadd_back(stack_a, tmp);
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

//include c files for testing purposes

int	main(int argc, char **argv)
{
	t_list 	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	

	ft_process_raw_args(argc, argv, &stack_a);
	printlist(stack_a);
	
	return (0);
}

