/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:32:30 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/16 12:09:29 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_parts_to_a(t_list **stack_a, t_list **stack_b,  int *cnt)
{
	int		max;
	int		turns;
	bool	ra_used;
	int		size;
	
	ra_used = false;
	max = 0;
	turns = 0;
	size = ft_list_size(*stack_b);
	while (size > 0)
	{
		max = ft_find_max(*stack_b);
		turns = ft_push_max_to_a(stack_a, stack_b, cnt, max, &ra_used);
		ft_restore_stack(stack_b, cnt, turns, ra_used);
		ra_used = false;
		size--;
	}
}

int	ft_push_max_to_a(t_list **stack_a, t_list **stack_b, int *cnt, int max, bool *ra_used)
{
	int	mid;
	int	pos;
	int	size;
	int	turns;
	
	size = ft_list_size(*stack_b);
	mid = ft_find_middle(size);
	turns = 0;
	pos = ft_find_node(*stack_b, max);
	while (pos != 1 && size > 1)
	{
		if (pos <= mid)
		{
			rb(stack_b, cnt);
			*ra_used = true;
		}
		if (pos > mid)
			rrb(stack_b, cnt);
		if (ft_stack_sorted(*stack_b) == true)
			break ;
		pos = ft_find_node(*stack_b, max);
		turns++;
	}
	pa(stack_a, stack_b, cnt);
	return (turns);
}


void	ft_restore_stack(t_list **stack_b, int *cnt, int turns, bool ra_used)
{
	if (!*stack_b || !stack_b)
		return ;
	while (turns != 0)
	{
		if (ra_used == true)
			rrb(stack_b, cnt);

		else
			rb(stack_b, cnt);
		turns--;
	}
}






//TODO: add in restore stack!
// int	max;
// 	int	pos;

// 	max = 0;
// max = ft_find_max(*stack_b);
// pos = ft_find_node(*stack_b, max);
// if (pos == 1)
// {
// 	pa(stack_a, stack_b, cnt);
// 	turns--;	
// }