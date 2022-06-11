/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:16:07 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/11 14:45:11 by rmazurit         ###   ########.fr       */
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
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}