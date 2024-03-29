/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_finders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:17:21 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/21 20:01:44 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Searches for a specified num within the stack.
	Returns the position of the element in the stack (first element hast pos 1).
	If no element found or stack is to small/consists of 1 element, returns 0.
*/
int	ft_find_node(t_list *stack, int to_find)
{
	int	pos;

	if (!stack)
		return (1);
	pos = 1;
	while (stack != NULL)
	{
		if (stack->nbr == to_find)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (1);
}

/*
	Find the middle of the stack.
	Set the middle 1 step closer to the beginning of the stack.
*/
int	ft_find_middle(int size)
{
	int	mid;

	if (size % 2 == 0)
		mid = (size / 2) + 1;
	else
		mid = (size / 2);
	return (mid);
}

/*
	Find the element on the position (provided as parameter) in the stack.
*/
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
