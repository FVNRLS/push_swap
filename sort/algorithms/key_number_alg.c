/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_number_alg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 19:23:57 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/15 17:13:54 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	Create a stack of the same number of elements as in stack a.
	Copy the numbers from a to b (no push/swap instructions).
	Return the  stack.
*/
t_list	*ft_create_key_stack(t_list *stack_a)
{
	t_list	*key_stack;
	t_list	*tmp;
	
	key_stack = NULL;
	while (stack_a != NULL)
	{
		tmp = ft_new_node(stack_a->nbr);
		ft_add_back(&key_stack, tmp);
		stack_a = stack_a->next;
	}
	return (key_stack);
}

/*
	Bubble sort of the key stack (Sort in ascending order).
*/
void	ft_sort_key_stack(t_list **key_stack)
{
	t_list	*node;
	int		i;
	int		len;
	int		tmp;
	
	node = *key_stack;
	len = ft_list_size(*key_stack) - 1;
	i = 0;
	while (len > 0)
	{
		while (i < len)
		{
			if (node->nbr > node->next->nbr)
			{
				tmp = node->nbr;
				node->nbr = node->next->nbr;
				node->next->nbr = tmp;
			}
			node = node->next;
			i++;
		}
		i = 0;
		node = *key_stack;
		len--;
	}
}

/*
	Divide the key stack in 'parts', depending on stack size.
	--> PARTS = number of chunks, to divide the stack in.
	Find the first position of the key number:
		Element on the position (size / parts) is the key.
		-> KEY is the max. element of the first chunk
	Return the key.
*/
int	ft_find_next_key(t_list *key_stack, int parts, int move)
{
	int	pos;
	int	size;
	int	key;
	
	size = ft_list_size(key_stack);
	pos = size / parts;
	pos *= move;
	key = ft_find_pos(key_stack, pos);
	return (key);
}

/*
	Combine 3 functions to get the key element:
	1) create a key stack
	2) sort the key stack
	3) find the key number
	4) delete
*/
int	ft_get_key(t_list **stack_a, t_list **key_stack, int parts, int move)
{
	int		key;
	
	*key_stack = ft_create_key_stack(*stack_a);
	ft_sort_key_stack(key_stack);
	key = ft_find_next_key(*key_stack, parts, move);
	return (key);
}
