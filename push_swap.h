/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:22:37 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/20 18:31:01 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

# define DELIMETER ' '

typedef struct	s_list
{
	int				nbr;
	struct s_list	*next;
}				t_list;

/* LIST MANAGEMENT*/
t_list 		*ft_new_node(int value);
void		ft_add_back(t_list **lst, t_list *new);
void		ft_add_front(t_list **lst, t_list *new);
void		ft_del_last(t_list **stack);
void		ft_delete_stack(t_list **stack);
/* ARGUMENTS MANAGEMENT (processing, checking)*/
bool		ft_create_stack(int argc, char **argv, t_list **stack);
/* ERROR MANAGEMENT */
bool		ft_input_invalid(bool error_flag);
bool		ft_duplicates_found(t_list *stack);
void		ft_check_num_range(long	res, bool *error);
void		ft_check_invalid_chars(char *str,  bool *error);



/* INSCTRUCTIONS */
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);

/* SORTING */
/* LIST CHECKERS */
bool	ft_stack_sorted(t_list *stack);
bool	ft_stack_is_small(int size);
bool	ft_stack_is_medium(int size);
bool	ft_stack_is_big(int size);

/* MIN/MAX FINDERS */
int		ft_find_min(t_list *stack);
int		ft_find_next_min(t_list *stack, int min);
int		ft_find_max(t_list *stack);
int		ft_find_next_max(t_list *stack, int max);
/* POS FINDERS */
int		ft_find_node(t_list *stack, int to_find);
int		ft_find_pos(t_list *stack, int pos_to_find);
int		ft_find_middle(int size);

/* COUNTERS */
int		ft_list_size(t_list *stack);
int		ft_set_parting(int size);

/* SORTERS */

/* ALGORITHMS */
/* SMALL SIZE STACK SORT */
void	ft_sort_small(t_list **stack_a, t_list **stack_b);
void	ft_sort_to_b(t_list **stack_a, t_list **stack_b);
void	ft_sort_last_3(t_list **stack);
void	ft_push_back_to_a(t_list **stack_a, t_list **stack_b);
/* MEDIUM/BIG SIZE STACK SORT */
void	ft_sort_big(t_list **stack_a, t_list **stack_b);
void	ft_push_chunks_to_b(t_list **stack_a, t_list **stack_b, t_list **key_stack);
void	ft_push_part_to_b(t_list **stack_a, t_list **stack_b, int key);
void	ft_push_element_to_b(t_list **stack_a, t_list **stack_b, int nbr);
bool	ft_part_is_pushed(t_list *stack_a, int key);


void	ft_sort_parts_to_a(t_list **stack_a, t_list **stack_b);
void	ft_push_maxes(t_list **stack_a, t_list **stack_b, int max, int nmax);
void	ft_push_nmax_over_top(t_list **stack_a, t_list **stack_b, int nmax);
void	ft_push_nmax_over_bottom(t_list **stack_a, t_list **stack_b, int nmax);
void	ft_push_max(t_list **stack_a, t_list **stack_b, int max, int mid);



/* CREATE KEY STACK AND FIND KEY ELEMENT*/
t_list	*ft_create_key_stack(t_list *stack_a);
void	ft_sort_key_stack(t_list **key_stack);
int		ft_find_next_key(t_list *key_stack, int parts, int move);
int		ft_get_key(t_list **stack_a, t_list **key_stack, int parts, int move);


/* TOOLS */
unsigned int	ft_strlen(char *s);
char			**ft_split(char *s, char c);
long			ft_atol(char *str, bool *error);
bool			ft_is_digit(char c);

/*TODO: DELETE!!!*/
# include "./argument_processors/nodes_managers.c"
# include "./argument_processors/argument_managers.c"
# include "./argument_processors/error_managers.c"

# include "./finders_and_counters/counters.c"
# include "./finders_and_counters/key_number_finder.c"
# include "./finders_and_counters/limit_finders.c"
# include "./finders_and_counters/list_checkers.c"
# include "./finders_and_counters/position_finders.c"

# include "./instructions/push_swap.c"
# include "./instructions/rotate.c"
# include "./instructions/reverse_rotate.c"

# include "./sorters/big_stack_sorter.c"
# include "./sorters/small_stack_sorter.c"
# include "./sorters/stack_b_sorter.c"

# include "./tools/ft_atol.c"
# include "./tools/ft_is_digit.c"
# include "./tools/ft_split.c"
# include "./tools/ft_strlen.c"

#endif
