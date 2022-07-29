/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sorter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:51:17 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/22 10:44:29 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Push all elements from STACK B to A
*/
static void	ft_push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}

/*
	Different cases for sorting of the last 3 eleemnts in STACK A:
	
	case1 :	[2,1,3]	->	sa	->	[1,2,3].
	case2 : [3,2,1]	->	sa	->	[2,3,1]	->	rra	->	[1,2,3].
	case3: 	[3,1,2]	->	ra	->	[1,2,3].
	case4 : [1,3,2]	->	sa	->	[3,1,2]	->	ra	->	[1,2,3].
	case5 : [2,3,1]	->	rra	->	[1,2,3].
*/
void	ft_sort_last_3(t_list **stack)
{
	int	n_1;
	int	n_2;
	int	n_3;

	n_1 = (*stack)->nbr;
	n_2 = (*stack)->next->nbr;
	n_3 = (*stack)->next->next->nbr;
	if ((n_1 > n_2) && (n_1 < n_3) && (n_2 < n_3))
		sa(stack);
	else if ((n_1 > n_2) && (n_1 > n_3) && (n_2 > n_3))
	{
		sa(stack);
		rra(stack);
	}
	else if ((n_1 > n_2) && (n_1 > n_3) && (n_2 < n_3))
		ra(stack);
	else if ((n_1 < n_2) && (n_1 < n_3) && (n_2 > n_3))
	{
		sa(stack);
		ra(stack);
	}
	else if ((n_1 < n_2) && (n_1 > n_3) && (n_2 > n_3))
		rra(stack);
}

/*
	Find the min. number in stack a and push it to b.
	Pushing way depends on the elements posiition regarding the middle.
	Perform the operations, until only 3 elements in stack a are left.
*/
void	ft_sort_to_b(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	min;
	int	mid;
	int	pos;

	size = ft_list_size(*stack_a);
	while (size > 3)
	{
		min = ft_find_min(*stack_a);
		mid = ft_find_middle(size);
		pos = ft_find_node(*stack_a, min);
		while (pos != 1)
		{
			if (pos <= mid)
				ra(stack_a);
			else if (pos > mid)
				rra(stack_a);
			if (ft_stack_sorted(*stack_a) == true)
				return ;
			pos = ft_find_node(*stack_a, min);
		}
		pb(stack_a, stack_b);
		size--;
	}
}

/*
	Sorting algorithm for <= 10 stack elements.
	Sort the smallest elements to b, until only 3 elements are left in STACK A.
	Then sort the 3 elements with the most efficient way.
	Push all elements back from STACK B to A.
*/
void	ft_sort_small(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_list_size(*stack_a);
	if (ft_stack_sorted(*stack_a) == true)
		return ;
	if (size == 2)
	{
		sa(stack_a);
		return ;
	}
	ft_sort_to_b(stack_a, stack_b);
	if (ft_stack_sorted(*stack_a) == false)
		ft_sort_last_3(stack_a);
	ft_push_back_to_a(stack_a, stack_b);
}
