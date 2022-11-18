/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit_finders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:36:39 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/21 19:53:56 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Find the smallest element in the stack and return its value.
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
	Find the biggest element in the stack and return its value.
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

/*
	Find the next biggest element in the stack and return its value.
*/
int	ft_find_next_max(t_list *stack, int max)
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
