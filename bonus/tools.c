/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:22:16 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/21 14:49:08 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_buf(char **buf)
{
	free(*buf);
	*buf = NULL;
}

void	ft_reset_buf(char **buf)
{
	int		i;
	char *tmp;
	
	tmp = *buf;
	i = 0;
	while (i < 4)
	{
		tmp[i] = '\0';
		i++;
	}
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (((*s1 != '\0') || (*s2 != '\0')) && (i < n))
	{
		if (*s1 < *s2)
			return (-1);
		else if (*s1 > *s2)
			return (1);
		s1++;
		s2++;
		i++;
	}
	return (0);
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
