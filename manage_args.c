/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:40:30 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/10 15:09:00 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_is_number(char c)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
		
// 	}
// 	return (1);
// }

int	ft_atoi(const char *str, int *error_flag)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-')
	{
		sign *= (-1);
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] <= '9' && str[i] >= '0')
			res = (str[i] - '0') + (res * 10);
		else
		{
			*error_flag = 1;
			return (1);
		}
		i++;
	}
	return (res * sign);
}

int	ft_input_invalid(int error_flag)
{
	if (error_flag == 1)
	{
		write (1, "Error! Invalid arguments provided.\n", 35);
		return (1);
	}
	return (0);
}