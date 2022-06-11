/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:16:46 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/11 19:59:40 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	TODO: 
	3) Find place to insert
	4) Count operations

	in the end free all stacks!
	//TODO: change error message to "Error"!
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

	if (ft_test(&stack_a, &stack_b, argc, argv) == false)
		return (1);
	
	return (0);
}
