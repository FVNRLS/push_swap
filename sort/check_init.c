/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:28:35 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/11 19:01:47 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ft_stack_a_sorted(t_list *stack_a)
{
	if (!stack_a->next || !stack_a)
		return (false);
	while (stack_a->next != NULL)
	{
		if (stack_a->nbr > stack_a->next->nbr)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

bool	ft_stack_b_sorted(t_list *stack_b)
{
	if (!stack_b->next || !stack_b)
		return (false);
	while (stack_b->next != NULL)
	{
		if (stack_b->nbr < stack_b->next->nbr)
			return (false);
		stack_b = stack_b->next;
	}
	return (true);
}

int	ft_find_max(t_list *stack)
{
	int	max;
	
	if (!stack || !stack->next)
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

int	ft_list_size(t_list *stack)
{
	int	size;

	if (!stack)
		return (0);
	if (!stack->next)
		return(1);
	size = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}