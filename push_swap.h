/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:22:37 by rmazurit          #+#    #+#             */
/*   Updated: 2022/05/28 18:02:43 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

# include "./libft/libft.h"

#include "manage_nodes.c"

// typedef struct	s_list
// {
// 	int				nbr;
// 	struct s_list	*next;
// }				t_list;

void		insert_after_node(t_list *node_to_insert_after, t_list *newnode);
void		insert_at_head(t_list **head, t_list *node_to_insert);
t_list 		*create_new_node(int value);
void		printlist(t_list *head);





#endif
