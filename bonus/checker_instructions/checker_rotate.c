/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:43:45 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/21 13:43:05 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	Checker version. (Wthout writing the instruction to stdout)
	Rotate a: 
	Shift up all elements of stack a by 1.
	The first element becomes the last one.
*/
void	ch_ra(t_list **stack)
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
}

/*
	Checker version. (Wthout writing the instruction to stdout)
	Rotate b: 
	Shift up all elements of stack b by 1.
	The first element becomes the last one.
*/

void	ch_rb(t_list **stack)
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
}

/*
	Checker version. (Wthout writing the instruction to stdout)
*/
void	ch_rr(t_list **stack_a, t_list **stack_b)
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
}
