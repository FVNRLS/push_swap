/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_sorter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:38:20 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/23 10:58:57 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Check whether the part was pushed or not.
	The indicator, that part was pushed is the absence of numbers in the stack,
	which are smaller or equal to the key number.
*/
static bool	ft_part_is_pushed(t_list *stack_a, int key)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->nbr <= key)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

/*
	Find 'nbr' in STACK A and push it to STACK B, based on instructions.
	To push the element, do following:
		1) Calculate the stack A size.
		2) Calculate the middle of the stack, based on stack size
		3) Find the node position in the stack.
		4) Compare the position against the middle.
			If pos <= mid -> rotate element to the top
			If pos <= mid -> rotate element to the bottom
		When the element reaches the position 0, push it to STACK B.
*/

static void	ft_push_element_to_b(t_list **stack_a, t_list **stack_b, int nbr)
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

/*
	Push all elements, which are smaller or equal to the key number (parameter)
	to the STACK B, using function ft_push_element_to_b().
*/
static void	ft_push_part_to_b(t_list **stack_a, t_list **stack_b, int key)
{
	t_list	*tmp;
	int		nbr;
	int		min;

	tmp = *stack_a;
	while (ft_part_is_pushed(*stack_a, key) == false)
	{
		nbr = tmp->nbr;
		if (nbr <= key)
			ft_push_element_to_b(stack_a, stack_b, nbr);
		min = ft_find_min(*stack_b);
		if (nbr == min)
			rb(stack_b);
		tmp = tmp->next;
		if (tmp == NULL)
			tmp = *stack_a;
	}
}

/*
	Push all parts except the last to STACK B.
	To identify the number of parts, set parting (depends on the stack size).
	Leave the last part in STACK A, to push it in sorted form in the end.
*/
static void	ft_push_chunks_to_b(t_list **st_a, t_list **st_b, t_list **key_st)
{
	int		move;
	int		parts;
	int		key;
	int		size;

	size = ft_list_size(*st_a);
	parts = ft_set_parting(size);
	move = 1;
	key = ft_get_key(st_a, key_st, parts, move);
	ft_push_part_to_b(st_a, st_b, key);
	move++;
	if (ft_stack_sorted(*st_a) == true)
		return ;
	while (move < parts)
	{
		key = ft_find_next_key(*key_st, parts, move);
		ft_push_part_to_b(st_a, st_b, key);
		move++;
	}
}

/*
	Sorting algorithm for medium/big stack size.
	Workflow:
		1) Divide the stack in parts, depending on the stack size.
		2) Push parts to STACK A, except the last one.
			-> the smaller part will be on the bottom of the STACK B, then comes
			a bigger part, than the bigger and so on...
		3) Sort the last part from STACK A to B
		4) Sort last 3 elements on STACK A
		5) Sort the pushed parts back from STACK A to B
*/
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
