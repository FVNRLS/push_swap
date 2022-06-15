/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:28:35 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/15 16:56:35 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ft_stack_sorted(t_list *stack)
{
	if (!stack->next || !stack)
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
	Stack contains 10 elements
*/
bool	ft_stack_is_small(int argc)
{
	if (argc <= 11)
		return (true);
	return (false);
}

/*
	Stack contains between 10 and 100 elements
*/
bool	ft_stack_is_medium(int argc)
{
	if (argc >= 11 && argc <= 101)
		return (true);
	return (false);
}

/*
	Stack contains more than 100 elements
*/
bool	ft_stack_is_big(int argc)
{
	if (argc > 101)
		return (true);
	return (false);
}
