/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_and_swap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:34:31 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/21 18:50:49 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	Checker version. (Without writing the instruction to stdout)
	Swap a.
	Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements.	
*/
void	ch_sa(t_list **stack)
{
	int	tmp;

	if (!*stack || !stack || !(*stack)->next)
		return ;
	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
}

/*
	Checker version. (Without writing the instruction to stdout)
	Swap b.
	Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements.	
*/
void	ch_sb(t_list **stack)
{
	int	tmp;

	if (!*stack || !stack || !(*stack)->next)
		return ;
	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
}

/*
	Checker version. (Without writing the instruction to stdout)
	sa and sb at the same time.
*/
void	ch_ss(t_list **stack_a, t_list **stack_b)
{
	int	tmp;

	if (!*stack_a || !stack_a || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->nbr;
	(*stack_a)->nbr = (*stack_a)->next->nbr;
	(*stack_a)->next->nbr = tmp;
	tmp = (*stack_b)->nbr;
	(*stack_b)->nbr = (*stack_b)->next->nbr;
	(*stack_b)->next->nbr = tmp;
}

/* 	
	Checker version. (Without writing the instruction to stdout)
	Push a: 
	Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty. 
*/
void	ch_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!*stack_b || !stack_b)
		return ;
	tmp = ft_new_node((*stack_b)->nbr);
	ft_add_front(stack_a, tmp);
	tmp = *stack_b;
	free(tmp);
	tmp = NULL;
	*stack_b = (*stack_b)->next;
}

/* 	
	Checker version. (Without writing the instruction to stdout)
	Push b: 
	Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty. 
*/
void	ch_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!*stack_a || !stack_a)
		return ;
	tmp = ft_new_node((*stack_a)->nbr);
	ft_add_front(stack_b, tmp);
	tmp = *stack_a;
	free(tmp);
	tmp = NULL;
	*stack_a = (*stack_a)->next;
}
