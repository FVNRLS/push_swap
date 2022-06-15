/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:16:46 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/15 17:38:16 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	rewrite find_node() in binary search!!!
*/

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list 	*stack_a;
	t_list	*stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	
	if (ft_create_stack(argc, argv, &stack_a) == false)
		return (1);
	else if (ft_duplicates_found(stack_a) == true)
		return (1);

	// PRINT INIT STATUS
	printf("\nINIT STATUS:");
	printlist(&stack_a, &stack_b);

	if (ft_stack_is_small(argc) == true)
		ft_sort_small(&stack_a, &stack_b, argc);
	else if (ft_stack_is_medium(argc) == true || ft_stack_is_big(argc) == true)
		ft_sort_big(&stack_a, &stack_b, argc);

	printlist(&stack_a, &stack_b);
	ft_delete_stack(&stack_a);
	ft_delete_stack(&stack_b);
	// system("leaks push_swap");
	return (0);
}
