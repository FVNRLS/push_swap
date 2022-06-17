/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:32:30 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/17 15:27:22 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_parts_to_a(t_list **stack_a, t_list **stack_b,  int *cnt)
{
	int		max;
	int		turns;
	int		size;
	
	if (!stack_b)
		return ;
	max = 0;
	turns = 0;
	size = ft_list_size(*stack_b);
	while (size > 0)
	{
		max = ft_find_max(*stack_b);
		ft_push_max_to_a(stack_a, stack_b, cnt, max);
		size--;
	}
}

void	ft_push_max_to_a(t_list **stack_a, t_list **stack_b, int *cnt, int max)
{
	int	mid;
	int	pos;
	int	size;
	
	size = ft_list_size(*stack_b);
	mid = ft_find_middle(size);
	pos = ft_find_node(*stack_b, max);
	while (pos != 1)
	{
		if (pos <= mid)
			rb(stack_b, cnt);
		else if (pos > mid)
			rrb(stack_b, cnt);
		pos = ft_find_node(*stack_b, max);
	}
	pa(stack_a, stack_b, cnt);
}
