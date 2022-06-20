/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:15:31 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/20 16:13:30 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

long	ft_atol(char *str, bool *error)
{
	int		i;
	long	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-')
	{
		sign *= (-1);
		i++;
	}
	while (str[i] != '\0')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	res = res * sign;
	ft_check_invalid_chars(str, error);
	ft_check_num_range(res, error);
	return (res);
}