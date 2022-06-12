/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:17:21 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/12 15:00:40 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_min(t_list *stack)
{
	int	min;
	
	if (!stack || !stack->next)
		return (INT_MAX);
	min = stack->nbr;
	while (stack != NULL)
	{
		if (stack->nbr < min)
			min = stack->nbr;
		stack = stack->next;
	}
	return (min);
}

/*
	Searches for a specified num within the stack.
	Returns the position of the element in the stack (first element hast pos 1).
	If no element found or stack is to small/consists of 1 element, returns 0.
*/
int	ft_find_node(t_list *stack, int to_find)
{
	int	pos;

	if (!stack || !stack->next)
		return (0);
	pos = 1;
	while (stack != NULL)
	{
		if (stack->nbr == to_find)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (0);
}

int	ft_find_middle(int size)
{
	int	mid;
	
	if (size % 2 == 0)
		mid = size / 2;
	else
		mid = (size / 2) + 1;
	return (mid);
}
