/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:43:45 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/19 15:08:42 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Rotate a: 
	Shift up all elements of stack a by 1.
	The first element becomes the last one.
*/
void	ra(t_list **stack, int *cnt)
{
	t_list	*tmp;
	
	if (!*stack || !stack)
		return ;
	tmp = ft_new_node((*stack)->nbr);
	ft_add_back(stack, tmp);
	tmp = *stack;
	free(tmp);
	tmp = NULL;
	*stack = (*stack)->next;
	write(1, "ra\n", 3);
	*cnt += 1;
}

/*
	Rotate b: 
	Shift up all elements of stack b by 1.
	The first element becomes the last one.
*/

void	rb(t_list **stack, int *cnt)
{
	t_list	*tmp;
	
	if (!*stack || !stack)
		return ;
	tmp = ft_new_node((*stack)->nbr);
	ft_add_back(stack, tmp);
	tmp = *stack;
	free(tmp);
	tmp = NULL;
	*stack = (*stack)->next;
	write(1, "rb\n", 3);
	*cnt += 1;
}

void	rr(t_list **stack_a, t_list **stack_b)
{	
	if (!*stack_a || !stack_a || !*stack_b || !stack_b)
		return ;
	t_list	*tmp;
	
	tmp = ft_new_node((*stack_a)->nbr);
	ft_add_back(stack_a, tmp);
	tmp = *stack_a;
	free(tmp);
	tmp = NULL;
	*stack_a = (*stack_a)->next;
	
	tmp = ft_new_node((*stack_b)->nbr);
	ft_add_back(stack_b, tmp);
	tmp = *stack_b;
	free(tmp);
	tmp = NULL;
	*stack_b = (*stack_b)->next;
	
	write(1, "rr\n", 3);
}
