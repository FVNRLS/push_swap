/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:32:30 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/18 14:00:51 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_parts_to_a(t_list **stack_a, t_list **stack_b,  int *cnt)
{
	int		max;
	int		turns;
	int		next_max;
	
	if (!stack_b)
		return ;
	max = 0;
	next_max = 0;
	turns = 0;
	while (*stack_b != NULL)
	{
		max = ft_find_max(*stack_b);
		// printf("\nmax:		%d", max);
		if ((*stack_b)->next != NULL)
		{
			next_max = ft_find_next_max(*stack_b, max);
			// printf("\nnext max:	%d\n", next_max);	
		}
		ft_push_max_to_a(stack_a, stack_b, cnt, max, next_max);
	}
}

void	ft_push_max_to_a(t_list **stack_a, t_list **stack_b, int *cnt, int max, int next_max)
{
	int		mid;
	int		size;
	int		pos_max;
	bool	next_max_pushed;
	
	size = ft_list_size(*stack_b);
	mid = ft_find_middle(size);
	pos_max = ft_find_node(*stack_b, max);
	next_max_pushed = false;
	if (pos_max != 1 && pos_max != 2)
		next_max_pushed = ft_push_next_max(stack_a, stack_b, cnt, next_max);
	while (pos_max != 1)
	{
		if (pos_max <= mid)
			rb(stack_b, cnt);
		else if (pos_max > mid)
			rrb(stack_b, cnt);
		pos_max = ft_find_node(*stack_b, max);
	}
	pa(stack_a, stack_b, cnt);
	if (next_max_pushed == true)
		sa(stack_a, cnt);
}

bool	ft_push_next_max(t_list **stack_a, t_list **stack_b, int *cnt, int next_max)
{
	int	pos_nmax;

	pos_nmax = ft_find_node(*stack_b, next_max);
	if (pos_nmax == 1)
	{
		pa(stack_a, stack_b, cnt);
		return (true);
	}
	else if (pos_nmax == 2)
	{	
		sb(stack_b, cnt);
		pa(stack_a, stack_b, cnt);
		return (true);
	}
	else
		return (false);
}