/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:03:11 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/22 11:58:24 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The function takes a string as an argument and returns its length. 
The returned value is an unsigned integer type. */

#include <stddef.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
