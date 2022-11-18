/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:16:07 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/21 18:53:19 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	Checker version. (Without writing the instruction to stdout)
	Reverse rotate a:
	Shift down all elements of stack a by 1.
	The last element becomes the first one.
*/
void	ch_rra(t_list **stack)
{
	t_list	*last;

	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last = ft_new_node(last->nbr);
	ft_add_front(stack, last);
	ft_del_last(stack);
}

/*
	Checker version. (Without writing the instruction to stdout)
	Reverse rotate b:
	Shift down all elements of stack b by 1. 
	The last element becomes the first one.
*/
void	ch_rrb(t_list **stack)
{
	t_list	*last;

	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last = ft_new_node(last->nbr);
	ft_add_front(stack, last);
	ft_del_last(stack);
}

/*
	Checker version. (Without writing the instruction to stdout)
	Do both instructions:
		rra and rrb
*/
void	ch_rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;

	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	last = ft_new_node(last->nbr);
	ft_add_front(stack_a, last);
	ft_del_last(stack_a);
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	last = ft_new_node(last->nbr);
	ft_add_front(stack_b, last);
	ft_del_last(stack_b);
}
