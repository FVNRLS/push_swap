/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:18:45 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/17 12:16:46 by rmazurit         ###   ########.fr       */
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
	int		parts;

	parts = 0;
	if (ft_stack_is_medium(size) == true)
		parts = 4;
	else if (ft_stack_is_big(size) == true)
		parts = 8;
	return (parts);
}