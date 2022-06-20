/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:35:18 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/20 15:41:18 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ft_input_invalid(bool error)
{
	if (error == true)
	{
		write(1, "Error\n", 6);
		return (true);
	}
	return (false);
}

void	ft_check_invalid_chars(char *str,  bool *error)
{
	int i;
	
	if (ft_strlen(str) > 11)
		*error = true;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			i++;
		if (ft_is_digit(str[i]) == false)
			*error = true;
		i++;
	}
	if (str[0] == '-' && (str[1] == '\0' || str[1] == '0'))
		*error = true;
	if (str[0] == '\0')
		*error = true;
}


void	ft_check_num_range(long	res, bool *error)
{
	if (res < INT_MIN || res > INT_MAX)
		*error = true;
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
				return (true);
		}
		next_node = pos->next;
		pos = pos->next;
	}
	return (false);
}
