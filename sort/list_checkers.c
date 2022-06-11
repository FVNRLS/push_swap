/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:28:35 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/11 23:05:57 by rmazurit         ###   ########.fr       */
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

bool	ft_stack_is_small(int argc)
{
	if (argc <= 10)
		return (true);
	return (false);
}

bool	ft_stack_is_medium(int argc)
{
	if (argc > 10 && argc <= 100)
		return (true);
	return (false);
}

bool	ft_stack_is_big(int argc)
{
	if (argc > 100)
		return (true);
	return (false);
}
