/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:18:45 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/19 16:32:12 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_list_size(t_list *stack)
{
	int	size;

	if (!stack)
		return (0);
	size = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

int	ft_set_parting(int size)
{
	float	parts;

	parts = 0;
	if (ft_stack_is_medium(size) == true)
	{
		if (size <= 25)
			parts = 2;
		else if (size <= 50)
			parts = 4;
		else if (size <= 75)
			parts = 5;
		else if (size <= 100)
			parts = 5.2;
	}
	else if (ft_stack_is_big(size) == true)
		parts = 14;
	return (parts);
}
