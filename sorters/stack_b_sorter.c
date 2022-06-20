/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:32:30 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/19 17:28:29 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_parts_to_a(t_list **stack_a, t_list **stack_b)
{
	int		max;
	int		nmax;
	
	if (!stack_b)
		return ;
	max = 0;
	nmax = 0;
	while (*stack_b != NULL)
	{
		max = ft_find_max(*stack_b);
		if ((*stack_b)->next != NULL)
			nmax = ft_find_next_max(*stack_b, max);
		ft_push_maxes(stack_a, stack_b, max, nmax);
	}
}

void	ft_push_maxes(t_list **stack_a, t_list **stack_b, int max, int nmax)
{
	int	pos_max;
	int	pos_nmax;
	int	size;
	int	mid;
	
	size = ft_list_size(*stack_b);
	mid = ft_find_middle(size);
	pos_max = ft_find_node(*stack_b, max);
	pos_nmax = ft_find_node(*stack_b, nmax);
	if ((pos_max <= mid) && (pos_nmax < mid) && (pos_nmax < pos_max))
	{
		ft_push_nmax_over_top(stack_a, stack_b, nmax);
		mid--;
		ft_push_max(stack_a, stack_b, max, mid);
		sa(stack_a);
	}
	else if ((pos_max > mid) && (pos_nmax > mid) && (pos_nmax > pos_max))
	{
		ft_push_nmax_over_bottom(stack_a, stack_b, nmax);
		mid--;
		ft_push_max(stack_a, stack_b, max, mid);
		sa(stack_a);
	}
	else
		ft_push_max(stack_a, stack_b, max, mid);
}

void	ft_push_nmax_over_top(t_list **stack_a, t_list **stack_b, int nmax)
{
	int	pos_nmax;
	
	pos_nmax = ft_find_node(*stack_b, nmax);
	while (pos_nmax != 1)
	{
		rb(stack_b);
		pos_nmax = ft_find_node(*stack_b, nmax);
	}
	pa(stack_a, stack_b);
}

void	ft_push_nmax_over_bottom(t_list **stack_a, t_list **stack_b, int nmax)
{
	int	pos_nmax;
	
	pos_nmax = ft_find_node(*stack_b, nmax);
	while (pos_nmax != 1)
	{
		rrb(stack_b);
		pos_nmax = ft_find_node(*stack_b, nmax);
	}
	pa(stack_a, stack_b);
}

void	ft_push_max(t_list **stack_a, t_list **stack_b, int max, int mid)
{
	int	pos_max;
	
	pos_max = ft_find_node(*stack_b, max);
	while (pos_max != 1)
	{
		if (pos_max <= mid)
			rb(stack_b);
		else if (pos_max > mid)
			rrb(stack_b);
		pos_max = ft_find_node(*stack_b, max);
	}
	pa(stack_a, stack_b);
}