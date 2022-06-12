/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:34:31 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/12 11:05:52 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Swap a.
	Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements.	
*/
void	sa(t_list **stack, int argc, int *cnt)
{
	int	tmp;
	
	if (!*stack || argc < 3)
		return ;
	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
	write(1, "sa\n", 3);
	*cnt += 1;
}

/*
	Swap b.
	Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements.	
*/
void	sb(t_list **stack, int argc, int *cnt)
{
	int	tmp;
	
	if (!*stack || argc < 3)
		return ;
	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
	write(1, "sb\n", 3);
	*cnt += 1;
}

/*
	sa and sb at the same time.
*/
void	ss(t_list **stack_a, t_list **stack_b, int argc, int *cnt)
{
	sa(stack_a, argc, cnt);
	sb(stack_b, argc, cnt);
	write(1, "ss\n", 3);
	*cnt += 1;
}

/* 	Push a: 
	Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty. 
*/
void	pa(t_list **stack_a, t_list **stack_b, int *cnt)
{
	t_list	*tmp;
	
	if (!*stack_b)
		return ;
	tmp = ft_new_node((*stack_b)->nbr);
	ft_add_front(stack_a, tmp);
	tmp = *stack_b;	//freeing the lost unused node
	free(tmp);
	tmp = NULL;
	*stack_b = (*stack_b)->next;
	write(1, "pa\n", 3);
	*cnt += 1;
}

/* 	Push b: 
	Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty. 
*/
void	pb(t_list **stack_a, t_list **stack_b, int *cnt)
{
	t_list	*tmp;
	
	if (!*stack_a)
		return ;
	tmp = ft_new_node((*stack_a)->nbr);
	ft_add_front(stack_b, tmp);
	tmp = *stack_a;	//freeing the lost unused node
	free(tmp);
	tmp = NULL;
	*stack_a = (*stack_a)->next;
	write(1, "pb\n", 3);
	*cnt += 1;
}
