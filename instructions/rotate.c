/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:43:45 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/11 13:17:48 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Rotate a: 
	Shift up all elements of stack a by 1.
	The first element becomes the last one.
*/

void	ra(t_list **stack)
{
	t_list	*tmp;
	
	tmp = ft_new_node((*stack)->nbr);
	
	ft_add_back(stack, tmp);
	tmp = *stack;
	free(tmp);
	tmp = NULL;
	*stack = (*stack)->next;
}

/*
	Rotate b: 
	Shift up all elements of stack b by 1.
	The first element becomes the last one.
*/

void	rb(t_list **stack)
{
	t_list	*tmp;
	
	tmp = ft_new_node((*stack)->nbr);
	
	ft_add_back(stack, tmp);
	tmp = *stack;
	free(tmp);
	tmp = NULL;
	*stack = (*stack)->next;
}

void	rr(t_list **stack_a, t_list **stack_b)
{	
	ra(stack_a);
	rb(stack_b);
}
