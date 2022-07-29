/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:43:45 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/21 20:10:31 by rmazurit         ###   ########.fr       */
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

	tmp = NULL;
	if (!*stack)
		return ;
	tmp = ft_new_node((*stack)->nbr);
	ft_add_back(stack, tmp);
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	tmp = NULL;
	write(1, "ra\n", 3);
}

/*
	Rotate b: 
	Shift up all elements of stack b by 1.
	The first element becomes the last one.
*/

void	rb(t_list **stack)
{
	t_list	*tmp;

	if (!*stack)
		return ;
	tmp = ft_new_node((*stack)->nbr);
	ft_add_back(stack, tmp);
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	tmp = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{	
	t_list	*tmp;

	if (!*stack_a || !*stack_b)
		return ;
	tmp = ft_new_node((*stack_a)->nbr);
	ft_add_back(stack_a, tmp);
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	free(tmp);
	tmp = NULL;
	tmp = ft_new_node((*stack_b)->nbr);
	ft_add_back(stack_b, tmp);
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	free(tmp);
	tmp = NULL;
	write(1, "rr\n", 3);
}
