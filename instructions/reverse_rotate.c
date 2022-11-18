/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:16:07 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/21 20:09:34 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Reverse rotate a:
	Shift down all elements of stack a by 1.
	The last element becomes the first one.
*/
void	rra(t_list **stack)
{
	t_list	*last;

	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last = ft_new_node(last->nbr);
	ft_add_front(stack, last);
	ft_del_last(stack);
	write(1, "rra\n", 4);
}

/*
	Reverse rotate b:
	Shift down all elements of stack b by 1. 
	The last element becomes the first one.
*/
void	rrb(t_list **stack)
{
	t_list	*last;

	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last = ft_new_node(last->nbr);
	ft_add_front(stack, last);
	ft_del_last(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
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
	write(1, "rrr\n", 4);
}
