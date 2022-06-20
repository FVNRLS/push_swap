/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:33:11 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/20 19:35:43 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <stdio.h>

void	ft_reset_buf(char **buf);
void	*ft_calloc(size_t count, size_t size);
bool	ft_nl_found(char *str);
// ft_nl_found()
//ft_strncmp()

#define	EXIT_SUCCESS	0
#define	EXIT_FAILURE	1
#define EXIT_ERROR 		2




#include "./bonus/tools.c"


#endif