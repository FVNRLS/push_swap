/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:38:20 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/14 15:01:04 by rmazurit         ###   ########.fr       */
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
	int		nbrs_left;

	parts = ft_set_parting(argc);
	move = 1;
	cnt = 0;
	key = 0;
	if (ft_stack_a_sorted(*stack_a) == true)
		return (cnt);
	
	while (move < parts)
	{
		if (key == 0)
		{
			key = ft_get_key(stack_a, &key_stack, parts, move);
			ft_push_part_to_b(stack_a, stack_b, &cnt, key);
		}
		else
		{
			key = ft_find_next_key(key_stack, parts, move);
			ft_push_part_to_b(stack_a, stack_b, &cnt, key);
		}
		printlist(stack_a, stack_b);
		move++;
	}
	nbrs_left = ft_list_size(*stack_a) - 3;
	printf("nbrs left: %d", nbrs_left);
	ft_sort_to_b(stack_a, stack_b, &cnt);
	ft_sort_last_3(stack_a, argc, &cnt);
	printlist(stack_a, stack_b); //
	while (nbrs_left > 0)
	{
		pa(stack_a, stack_b, &cnt);
		nbrs_left--;
	}
	printlist(stack_a, stack_b); //
	

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
			tmp = *stack_a; //TODO: check if it's more effective (by now-> more instructions, but no crashes / loops)
		}
		tmp = tmp->next;
		if (tmp == NULL)
			tmp = *stack_a;
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
		if (pos <= mid && pos != 1)
			ra(stack_a, cnt);
		if (pos > mid)
			rra(stack_a, cnt);
		if (ft_stack_a_sorted(*stack_a) == true)
			return ;
		pos = ft_find_node(*stack_a, nbr);
	}
	pb(stack_a, stack_b, cnt);
	printlist(stack_a, stack_b); //
}

int	ft_push_element_to_a(t_list **stack_a, t_list **stack_b, int *cnt, int nbr)
{
	int	mid;
	int	pos;
	int	size;
	int	turns;
	
	size = ft_list_size(*stack_b);
	mid = ft_find_middle(size);
	pos = 0;
	while (pos != 1)
	{
		if (pos <= mid && pos != 1)
			ra(stack_b, cnt);
		if (pos > mid)
			rra(stack_a, cnt);
		if (ft_stack_a_sorted(*stack_a) == true)
			return ;
		pos = ft_find_node(*stack_a, nbr);
		turns++;
	}
	pa(stack_a, stack_b, cnt);
	turns++;
	printlist(stack_a, stack_b); //
	return (turns);
}

//TODO: finish!
void	ft_sort_parts_to_a(t_list **stack_a, t_list **stack_b,  int *cnt)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		i;
	int		max;
	int		pos;
	int		turns;
	
	tmp_a = *stack_a;
	tmp_b = *stack_b;
	max = 0;
	i = 0;
	while (tmp_b != NULL)
	{
		max = ft_find_max(stack_b);
		turns = ft_push_element_to_a(stack_a, stack_b, cnt, max);
		//TODO: turn so many times like turns!
	}
	
	
}