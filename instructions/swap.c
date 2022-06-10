/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:34:31 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/10 23:11:37 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Swap a.
	Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements.	
*/
void	sa(t_list **stack, int argc)
{
	int	tmp;
	
	if (!*stack || argc < 3)
		return ;
	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
}

/*
	Swap b.
	Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements.	
*/
void	sb(t_list **stack, int argc)
{
	int	tmp;
	
	if (!*stack || argc < 3)
		return ;
	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
}

/*
	sa and sb at the same time.
*/
void	ss(t_list **stack_a, t_list **stack_b, int argc)
{
	sa(stack_a, argc);
	sb(stack_b, argc);
}