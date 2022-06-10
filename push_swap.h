/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:22:37 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/11 00:15:38 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

# define DELIMETER ' '

typedef struct	s_list
{
	int				nbr;
	struct s_list	*next;
}				t_list;

/* LIST MANAGEMENT*/
t_list 		*ft_new_node(int value);
t_list		*ft_last_node(t_list *lst);
void		ft_add_back(t_list **lst, t_list *new);
void		printlist(t_list *stack_a, t_list *stack_b); // TODO: delete!

/* ARGUMENTS MANAGEMENT (processing, checking)*/
bool		ft_create_stack(int argc, char **argv, t_list **stack);
bool		ft_input_invalid(bool error_flag);
bool		ft_duplicates_found(t_list *stack);

/* TOOLS */
unsigned int	ft_strlen(char *s);
char			**ft_split(char *s, char c);
int		ft_atoi(const char *str, bool *error_flag);

/* INSCTRUCTIONS */
void	sa(t_list **stack, int argc);
void	sb(t_list **stack, int argc);
void	ss(t_list **stack_a, t_list **stack_b, int argc);
void	pa(t_list **stack_a, t_list **stack_b);



/*TODO: DELETE!!!*/
# include "manage_nodes.c"
# include "manage_args.c"
# include "./tools/ft_split.c"
# include "./tools/ft_strlen.c"
# include "./tools/ft_atoi.c"
# include "./instructions/push_swap.c"


#endif
