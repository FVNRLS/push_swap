/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:38:20 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/19 17:21:26 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_sort_big(t_list **stack_a, t_list **stack_b)
{	
	t_list	*key_stack;

	if (ft_stack_sorted(*stack_a) == true)
		return ;
	ft_push_chunks_to_b(stack_a, stack_b, &key_stack);
	ft_sort_to_b(stack_a, stack_b);
	ft_sort_last_3(stack_a);
	ft_sort_parts_to_a(stack_a, stack_b);
	ft_delete_stack(&key_stack);
}

void	ft_push_chunks_to_b(t_list **stack_a, t_list **stack_b, t_list **key_stack)
{
	int		move;
	int		parts;
	int		key;
	int		size;
	
	size = ft_list_size(*stack_a);
	parts = ft_set_parting(size);
	move = 1;
	key = ft_get_key(stack_a, key_stack, parts, move);
	
	ft_push_part_to_b(stack_a, stack_b, key);
	move++;
	if (ft_stack_sorted(*stack_a) == true)
		return ;
	while (move < parts)
	{
		key = ft_find_next_key(*key_stack, parts, move);
		ft_push_part_to_b(stack_a, stack_b, key);
		move++;
	}
}

void	ft_push_part_to_b(t_list **stack_a, t_list **stack_b, int key)
{
	t_list	*tmp;
	int		nbr;
	int		min;

	tmp = *stack_a;
	nbr = 0;
	while (ft_part_is_pushed(*stack_a, key) == false)
	{
		nbr = tmp->nbr;
		if (nbr <= key)
			ft_push_element_to_b(stack_a, stack_b, nbr);
		min = ft_find_min(*stack_b);
		if (nbr == min && (*stack_a)->nbr > key)
			rr(stack_a, stack_b);
		else if (nbr == min)
			rb(stack_b);
		tmp = tmp->next;
		if (tmp == NULL)
			tmp = *stack_a;
	}
}

void	ft_push_element_to_b(t_list **stack_a, t_list **stack_b, int nbr)
{
	int	mid;
	int	pos;
	int	size;
	
	size = ft_list_size(*stack_a);
	mid = ft_find_middle(size);
	pos = ft_find_node(*stack_a, nbr);
	while (pos != 1)
	{
		if (pos <= mid)
			ra(stack_a);
		else if (pos > mid)
			rra(stack_a);
		if (ft_stack_sorted(*stack_a) == true)
			return ;
		pos = ft_find_node(*stack_a, nbr);
	}
	pb(stack_a, stack_b);
}

bool	ft_part_is_pushed(t_list *stack_a, int key)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->nbr <= key)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}
