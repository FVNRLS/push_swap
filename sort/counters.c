/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:18:45 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/13 11:04:52 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	ft_set_parting(int argc)
{
	int		parts;

	parts = 0;
	if (ft_stack_is_medium(argc) == true)
		parts = 4;
	else if (ft_stack_is_big(argc) == true)
		parts = 8;
	return (parts);
}