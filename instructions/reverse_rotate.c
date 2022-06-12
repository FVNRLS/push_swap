/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:16:07 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/12 11:06:51 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Reverse rotate a:
	Shift down all elements of stack a by 1.
	The last element becomes the first one.
*/
void	rra(t_list **stack, int *cnt)
{
	t_list	*last;
	
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last = ft_new_node(last->nbr);
	ft_add_front(stack, last);
	ft_del_last(stack);
	write(1, "rra\n", 4);
	*cnt += 1;
}

/*
	Reverse rotate b:
	Shift down all elements of stack b by 1. 
	The last element becomes the first one.
*/
void	rrb(t_list **stack, int *cnt)
{
	t_list	*last;
	
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last = ft_new_node(last->nbr);
	ft_add_front(stack, last);
	ft_del_last(stack);
	write(1, "rrb\n", 4);
	*cnt += 1;
}

void	rrr(t_list **stack_a, t_list **stack_b, int *cnt)
{
	rra(stack_a, cnt);
	rrb(stack_b, cnt);
	write(1, "rrr\n", 4);
	*cnt += 1;
}