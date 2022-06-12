/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_alg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:51:17 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/12 13:07:19 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	Sorting algorithm for <= 10 stack elements.
*/
int	ft_sort_small(t_list **stack_a, t_list **stack_b, int argc)
{
	int	size;
	int	min;
	int	mid;
	int	pos;
	int	cnt;
	
	size = ft_list_size(*stack_a);
	cnt = 0;
	while (size > 3)
	{
		if (ft_stack_a_sorted(*stack_a) == true)
			break ;
		min = ft_find_min(*stack_a);
		if (size % 2 == 0)
			mid = size / 2;
		else
			mid = (size / 2) + 1;
		pos = ft_find_node(*stack_a, min);
		if (pos <= mid)
		{
			while (pos != 1)
			{
				ra(stack_a, &cnt);
				pos = ft_find_node(*stack_a, min);
			}
		}
		else if (pos > mid)
		{
			while (pos != 1)
			{
				rra(stack_a, &cnt);
				pos = ft_find_node(*stack_a, min);
			}
		}
		pb(stack_a, stack_b, &cnt);
		size--;
		//TODO: delete!
		printlist(stack_a, stack_b);
	}
	ft_apply_cases(stack_a, argc, &cnt);
	ft_push_back_to_a(stack_a, stack_b, &cnt);
	printlist(stack_a, stack_b);
	printf("\nTotal Counter:	%d\n", cnt);
	return (cnt);
}

/*
	case1 :	[2,1,3]	->	sa	->	[1,2,3].
	case2 : [3,2,1]	->	sa	->	[2,3,1]	->	rra	->	[1,2,3].
	case3: 	[3,1,2]	->	ra	->	[1,2,3].
	case4 : [1,3,2]	->	sa	->	[3,1,2]	->	ra	->	[1,2,3].
	case5 : [2,3,1]	->	rra	->	[1,2,3].
*/
void	ft_apply_cases(t_list **stack, int argc, int *cnt)
{
	int	n_1;
	int	n_2;
	int	n_3;
	
	n_1 = (*stack)->nbr;
	n_2 = (*stack)->next->nbr;
	n_3 = (*stack)->next->next->nbr;
	if (ft_stack_a_sorted(*stack) == true)
			return ;
	else if ((n_1 > n_2) && (n_1 < n_3) && (n_2 < n_3))
		sa(stack, argc, cnt);
	else if ((n_1 > n_2) && (n_1 > n_3) && (n_2 > n_3))
	{
		sa(stack, argc, cnt);
		rra(stack, cnt);
	}
	else if ((n_1 > n_2) && (n_1 > n_3) && (n_2 < n_3))
		ra(stack, cnt);
	else if ((n_1 < n_2) && (n_1 < n_3) && (n_2 > n_3))
	{
		sa(stack, argc, cnt);
		ra(stack, cnt);
	}
	else if ((n_1 < n_2) && (n_1 > n_3) && (n_2 > n_3))
		rra(stack, cnt);
}

void	ft_push_back_to_a(t_list **stack_a, t_list **stack_b, int *cnt)
{
	while (*stack_b != NULL)
		pa(stack_a, stack_b, cnt);
}
