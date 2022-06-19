/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:35:18 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/19 19:05:15 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ft_input_invalid(bool error_flag)
{
	if (error_flag == true)
	{
		write(1, "Error\n", 6);
		return (true);
	}
	return (false);
}

bool	ft_duplicates_found(t_list *stack)
{
	t_list	*pos;
	t_list	*next_node;
	
	pos = stack;
	next_node = pos;
	while (pos != NULL)
	{
		while (next_node->next != NULL)
		{
			next_node = next_node->next;
			if (pos->nbr == next_node->nbr)
			{
				write(1, "Error\n", 6);
				return (true);
			}
		}
		next_node = pos->next;
		pos = pos->next;
	}
	return (false);
}
