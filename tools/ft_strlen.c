/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:03:11 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/10 15:29:37 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The function takes a string as an argument and returns its length. 
The returned value is an unsigned integer type. */

unsigned int	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
