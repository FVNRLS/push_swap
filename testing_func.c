/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:47:22 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/22 12:04:32 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	THiS FILE CONTAINS ONLY FUNCTIONS FOR TESTING PURPOSES AND DOESN'T COUNT
	TO THE PROJECT.
*/

#include "push_swap.h"

//TEST FILL STACK B with equal size of numbers to test against stack a
bool	ft_test(t_list **stack_a, t_list **stack_b, int argc, char **argv)
{
	t_list	*tmp;
	if (ft_create_stack(argc, argv, stack_b) == false)
		return (false);
	else if (ft_duplicates_found(*stack_b) == true)
		return (false);
	tmp = *stack_b;
	while (tmp != NULL)
	{
		tmp->nbr += 10;
		tmp = tmp->next;
	}

	//****************************************************

	/* TESTING INSTRUCTIONS
	printf("\nsa:");
	sa(stack_a, argc);
	printlist(stack_a, stack_b);
	
	printf("\nsb:");
	sb(stack_b, argc);
	printlist(stack_a, stack_b);
	
	printf("\nss:");
	ss(stack_a, stack_b, argc);
	printlist(stack_a, stack_b);
	
	printf("\npa:");
	pa(stack_a, stack_b);
	printlist(stack_a, stack_b);

	printf("\npb:");
	pb(stack_a, stack_b);
	printlist(stack_a, stack_b);

	printf("\nra:");
	ra(stack_a);
	printlist(stack_a, stack_b);

	printf("\nrb:");
	ra(stack_b);
	printlist(stack_a, stack_b);

	printf("\nrr:");
	rr(stack_a, stack_b);
	printlist(stack_a, stack_b);

	printf("\nrra:");
	rra(stack_a);
	printlist(stack_a, stack_b);

	printf("\nrrb:");
	rra(stack_b);
	printlist(stack_a, stack_b);

	printf("\nrrr:");
	rrr(stack_a, stack_b);
	printlist(stack_a, stack_b); */

	/* SORT CHECK */
	// ft_check_sort(*stack_a, *stack_b);

	/* FIND MIN CHECK */
	printf("\nThe min of STACK A:		%d", ft_find_min(*stack_a));
	printf("\nThe min of STACK B:		%d\n", ft_find_min(*stack_b));

	/* POSITION CHECK */
	printf ("The list size is:		%d\n",ft_list_size(*stack_a));
	printf ("The position of the min:	%d\n",ft_find_node(*stack_a, ft_find_min(*stack_a)));

	
	// LEAKS TEST
	system("leaks a.out");
	return (true);
}

//PRINT BOTH STACKS TO STDOUT
void	printlist(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	
	if (!*stack_a && !*stack_b)
		return ;
	printf("\nA	B\n");
	write(1, "---------\n", 10);
	while (tmp_a != NULL)
	{
		printf("%d", tmp_a->nbr);
		tmp_a = tmp_a->next;
		if (tmp_b != NULL)
		{
			printf("	%d", tmp_b->nbr);
			tmp_b = tmp_b->next;
		}
		printf("\n");
	}
	while (tmp_b != NULL)
	{
		printf("	%d\n", tmp_b->nbr);
		tmp_b = tmp_b->next;
	}
	printf("\n");
}


// CHECK IF THE STACK IS SORTED
void	ft_check_sort(t_list *stack_a, t_list *stack_b)
{
	if (ft_stack_sorted(stack_a) == true)
		printf("Stack A is sorted\n");
	if (ft_stack_sorted(stack_b) == true)
		printf("Stack B is sorted\n");
}