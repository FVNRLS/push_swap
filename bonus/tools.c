/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:22:16 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/20 19:48:43 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reset_buf(char **buf)
{
	int		i;
	char *tmp;
	
	tmp = *buf;
	i = 0;
	while (tmp[i] != '\0')
	{
		tmp[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	size_t	i;
	char	*buf;

	if (size > 0 && (SIZE_MAX / size) < count)
		return (NULL);
	total = size * count;
	buf = malloc(total);
	if (buf == NULL)
		return (NULL);
		i = 0;
	while (i < count)
		i++;
	buf[count] = '\0';
	return (buf);
}

bool	ft_nl_found(char *str)
{
	int	i;

	if (!str)
		return (false);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}
