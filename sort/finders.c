/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:17:21 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/18 16:00:00 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Find the smallest element in the stack and return it's value.
*/
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
	Find the biggest element in the stack and return it's value.
*/
int	ft_find_max(t_list *stack)
{
	int	max;
	
	if (!stack)
		return (INT_MIN);
	max = stack->nbr;
	while (stack != NULL)
	{
		if (stack->nbr > max)
			max = stack->nbr;
		stack = stack->next;
	}
	return (max);
}

int	ft_find_next_max(t_list *stack, int max) //here problem! segfault!
{
	int	next_max;
	
	if (!stack->next)
		return (0);
	if (stack->nbr != max)
		next_max = stack->nbr;
	else
	{
		next_max = stack->next->nbr;
		stack = stack->next;
	}
	while (stack != NULL)
	{
		if (stack->nbr > next_max && stack->nbr < max)
			next_max = stack->nbr;
		stack = stack->next;
	}
	return (next_max);
}

/*
	Searches for a specified num within the stack.
	Returns the position of the element in the stack (first element hast pos 1).
	If no element found or stack is to small/consists of 1 element, returns 0.
*/
int	ft_find_node(t_list *stack, int to_find)
{
	int	pos;

	if (!stack)
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
		mid = (size / 2) + 1;
	else
		mid = (size / 2);
	return (mid);
}

int	ft_find_pos(t_list *stack, int pos_to_find)
{
	int	pos;

	if (!stack)
		return (0);
	pos = 1;
	while (stack != NULL && pos != pos_to_find)
	{
		stack = stack->next;
		pos++;
	}
	return (stack->nbr);
}