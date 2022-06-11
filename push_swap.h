/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:22:37 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/11 19:51:40 by rmazurit         ###   ########.fr       */
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
void		ft_add_front(t_list **lst, t_list *new);


/* ARGUMENTS MANAGEMENT (processing, checking)*/
bool		ft_create_stack(int argc, char **argv, t_list **stack);
bool		ft_input_invalid(bool error_flag);
bool		ft_duplicates_found(t_list *stack);

/* TOOLS */
unsigned int	ft_strlen(char *s);
char			**ft_split(char *s, char c);
int				ft_atoi(const char *str, bool *error_flag);

/* INSCTRUCTIONS */
void	sa(t_list **stack, int argc);
void	sb(t_list **stack, int argc);
void	ss(t_list **stack_a, t_list **stack_b, int argc);
void	pa(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);

/* SORTING */
/* LIST CHECKERS */
bool	ft_stack_a_sorted(t_list *stack_a);
bool	ft_stack_b_sorted(t_list *stack_b);
/* FINDERS */
int		ft_find_min(t_list *stack);
int		ft_find_node(t_list *stack, int to_find);
/* COUNTERS */
int		ft_list_size(t_list *stack);
int		ft_distance_to_start(int pos);
int		ft_distance_to_end(t_list *stack, int pos);
/* SORTERS */
void	ft_sort_to_top(t_list **stack);
void	ft_sort_to_bottom(t_list **stack);




/* TESTING TODO: delete before submission!*/
bool		ft_test(t_list **stack_a, t_list **stack_b, int argc, char **argv);
void		printlist(t_list **stack_a, t_list **stack_b);
void		ft_check_sort(t_list *stack_a, t_list *stack_b);

/*TODO: DELETE!!!*/
# include "manage_nodes.c"
# include "manage_args.c"
# include "./tools/ft_split.c"
# include "./tools/ft_strlen.c"
# include "./tools/ft_atoi.c"
# include "./instructions/push_swap.c"
# include "./instructions/rotate.c"
# include "./instructions/reverse_rotate.c"
# include "testing_func.c"
# include "./sort/list_checkers.c"
# include "./sort/finders.c"
# include "./sort/counters.c"
# include "./sort/sorters.c"


#endif
