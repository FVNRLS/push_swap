/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:22:37 by rmazurit          #+#    #+#             */
/*   Updated: 2022/05/28 12:49:58 by rmazurit         ###   ########.fr       */
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

typedef struct	s_stack
{
	int				nbr;
	struct s_stack	*next;
}				t_stack;

void		insert_after_node(t_stack *node_to_insert_after, t_stack *newnode);
void		insert_at_head(t_stack **head, t_stack *node_to_insert);
t_stack 	*create_new_node(int value);
void		printlist(t_stack *head);





#endif
