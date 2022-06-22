/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:35:18 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/22 15:08:22 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Take the error - flag as argument.
	If the flag is set to true -> input is invalid.
		-> write arror message and return true.
	Otherwise return false.
*/
bool	ft_input_invalid(bool error)
{
	if (error == true)
	{
		write(2, "Error\n", 6);
		return (true);
	}
	return (false);
}

/* 
	Check for invalid characters inside the provided unconverted argument.
	An '0' sign before a number will be ignored.
	Also -0 is not considered as an error.
	Set error flag to true if:
		1) len of the argument is more than 11 (MIN_INT len incl. '-' sign).
		2) more than 1 minus sign was found.
		3) The argument is not a digit.
		4) No argument provided (string is empty).
*/
void	ft_check_invalid_chars(char *str, bool *error)
{
	int	i;

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
	if (str[0] == '-' && str[1] == '\0')
		*error = true;
	if (str[0] == '\0')
		*error = true;
}

/*
	Check if the calculated atol() result is in tolerant range of int type.
	Set error-flag to true, if the number is out of range.
*/
void	ft_check_num_range(long res, bool *error)
{
	if (res < INT_MIN || res > INT_MAX)
		*error = true;
}

/*
	Loop through the created stack and compare each element with the others.
	If equal elements found, set error-flag to true and return true.
	Otherwise return false.
*/
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
