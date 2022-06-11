/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:51:17 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/12 00:09:44 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Sorting algorithm for <= 10 stack elements.
*/
//TODO: infinite while loop!!!!
int	ft_sort_small(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	min;
	int	mid;
	int	pos;
	int	cnt;
	
	size = ft_list_size(*stack_a);
	while (size > 3)
	{
		min = ft_find_min(*stack_a);
		mid = size / 2;
		pos = ft_find_node(*stack_a, min);
		if (mid < pos)
		{
			while (pos != 1)
			{
				ra(stack_a);
				printlist(stack_a, stack_b);
				cnt++;
			}
		}
		else if (mid > pos)
		{
			while (pos != 1)
			{
				rra(stack_a);
				printlist(stack_a, stack_b);
				cnt++;
			}
		}
		pb(stack_a, stack_b);
		cnt++;
		size--;
		printlist(stack_a, stack_b);
		printf("Counter:	%d", cnt);
	}
	return (cnt);
}

/* TODO:
	case1 : [2,1,3]->sa->[1,2,3].

	case2 : [3,2,1]->sa->[2,3,1]->rra->[1,2,3].

	case3: [3,1,2]->ra->[1,2,3].

	case4 : [1,3,2]->sa->[3,1,2]->ra->[1,2,3].

	case5 : [2,3,1]->rra->[1,2,3].
*/