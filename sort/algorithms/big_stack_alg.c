/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:38:20 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/12 20:02:04 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_sort_big(t_list **stack_a/* , t_list **stack_b*/, int argc)
{	
	t_list	*key_stack;
	int		key;
	int		cnt;
	
	cnt = 0;
	if (ft_stack_a_sorted(*stack_a) == true)
		return (cnt);
		
	//divide in chunks and put to b
	key = ft_get_key(stack_a, &key_stack, argc);
	printf("\nkey:	%d", key);



	// if (ft_stack_a_sorted(*stack_a) == false)
	// 	ft_apply_cases(stack_a, argc, &cnt);
	// ft_push_back_to_a(stack_a, stack_b, &cnt);
	
	// //TODO: delete!
	// printlist(stack_a, stack_b);
	// printf("\nTotal Counter:	%d\n", cnt);
	ft_delete_stack(&key_stack);
	return (cnt);
}

