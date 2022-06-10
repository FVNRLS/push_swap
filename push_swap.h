/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:22:37 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/10 15:03:36 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct	s_list
{
	int				nbr;
	struct s_list	*next;
}				t_list;

t_list 		*ft_new_node(int value);
t_list		*ft_last_node(t_list *lst);
void		ft_add_back(t_list **lst, t_list *new);
void		printlist(t_list *stack); // TODO: delete!

int			ft_atoi(const char *str, int *error_flag);
int			ft_input_invalid(int error_flag);




#include "manage_nodes.c"
#include "manage_args.c"

#endif
