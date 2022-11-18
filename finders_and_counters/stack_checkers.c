/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:28:35 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/21 19:54:53 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Check if the stack is sorted in ascending order.
	If yes - return true, otherwise return false.
*/
bool	ft_stack_sorted(t_list *stack)
{
	if (!stack->next)
		return (false);
	while (stack->next != NULL)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

/*
	Stack contains 10 elements or less
*/
bool	ft_stack_is_small(int size)
{
	if (size <= 10)
		return (true);
	return (false);
}

/*
	Stack contains between 11 and 100 elements
*/
bool	ft_stack_is_medium(int size)
{
	if (size >= 11 && size <= 100)
		return (true);
	return (false);
}

/*
	Stack contains more than 100 elements
*/
bool	ft_stack_is_big(int size)
{
	if (size > 100)
		return (true);
	return (false);
}
