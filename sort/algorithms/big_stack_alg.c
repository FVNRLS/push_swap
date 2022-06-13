/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:38:20 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/13 20:02:18 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_sort_big(t_list **stack_a, t_list **stack_b, int argc)
{	
	t_list	*key_stack;
	int		key;
	int		cnt;
	int		move;
	int		parts;

	parts = ft_set_parting(argc);
	move = 1;
	cnt = 0;
	if (ft_stack_a_sorted(*stack_a) == true)
		return (cnt);
	
	key = ft_get_key(stack_a, &key_stack, parts, move);

	ft_push_part_to_b(stack_a, stack_b, &cnt, key);
	move++;
	printlist(stack_a, stack_b);
	
	key = ft_find_next_key(key_stack, parts, move);
	ft_push_part_to_b(stack_a, stack_b, &cnt, key);
	move++;
	printlist(stack_a, stack_b);

	// while (move != parts + 1)
	// {	
	// 	ft_push_part_to_b(stack_a, stack_b, &cnt, key);
	// 	key = ft_find_next_key(key_stack, parts, move);
	// 	move++;
	// }
	

	// if (ft_stack_a_sorted(*stack_a) == false)
	// 	ft_apply_cases(stack_a, argc, &cnt);
	// ft_push_back_to_a(stack_a, stack_b, &cnt);
	
	// //TODO: delete!
	// printlist(stack_a, stack_b);
	// printf("\nTotal Counter:	%d\n", cnt);
	//TODO: delete!
	printf("\nTotal Instructions:	%d\n", cnt);
	ft_delete_stack(&key_stack);
	return (cnt);
}

void	ft_push_part_to_b(t_list **stack_a, t_list **stack_b, int *cnt, int key)
{
	t_list	*tmp;
	int		nbr;

	tmp = *stack_a;
	nbr = 0;
	while (ft_part_is_pushed(*stack_a, key) != true)
	{
		nbr = tmp->nbr;
		if (nbr <= key)
		{
			ft_push_element_to_b(stack_a, stack_b, cnt, nbr);
			tmp = *stack_a;
		}
		tmp = tmp->next;
	}
}

bool	ft_part_is_pushed(t_list *stack_a, int key)
{
	while (stack_a != NULL)
	{
		if (stack_a->nbr <= key)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

void	ft_push_element_to_b(t_list **stack_a, t_list **stack_b, int *cnt, int nbr)
{
	int	mid;
	int	pos;
	int	size;
	
	size = ft_list_size(*stack_a);
	mid = ft_find_middle(size);
	pos = 0;
	while (pos != 1)
	{
		if (pos <= mid)
			ra(stack_a, cnt);
		if (pos > mid)
			rra(stack_a, cnt);
		if (ft_stack_a_sorted(*stack_a) == true)
			return ;
		pos = ft_find_node(*stack_a, nbr);
	}
	pb(stack_a, stack_b, cnt);
	
	//TODO: delete!
	printlist(stack_a, stack_b);
}
