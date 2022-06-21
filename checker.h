/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:33:11 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/21 18:27:47 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define EXIT_SUCCESS	0
# define EXIT_ERROR 	1

/* BONUS TOOLS */
void	ft_free_buf(char **buf);
void	ft_reset_buf(char **buf);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
bool	ft_nl_found(char *str);

/* CHECKER INSTRUCTIONS */
void	ch_sa(t_list **stack);
void	ch_sb(t_list **stack);
void	ch_ss(t_list **stack_a, t_list **stack_b);
void	ch_pa(t_list **stack_a, t_list **stack_b);
void	ch_pb(t_list **stack_a, t_list **stack_b);
void	ch_rra(t_list **stack);
void	ch_rrb(t_list **stack);
void	ch_rrr(t_list **stack_a, t_list **stack_b);
void	ch_ra(t_list **stack);
void	ch_rb(t_list **stack);
void	ch_rr(t_list **stack_a, t_list **stack_b);

#endif