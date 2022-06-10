/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:16:46 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/11 00:54:03 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list 	*stack_a;
	t_list	*stack_b;
	

	stack_a = NULL;
	stack_b = NULL;

	//TODO: delete!
	t_list	*tmp;
	ft_create_stack(argc, argv, &stack_b);
	tmp = stack_b;
	while (tmp->next != NULL)
	{
		tmp->nbr += 10;
		tmp = tmp->next;
	}
	tmp->nbr += 10;
	
	
	if (ft_create_stack(argc, argv, &stack_a) == false)
		return (1);
	else if (ft_duplicates_found(stack_a) == true)
		return (1);
	else
	{
		printf("\nINIT STATUS:\n\n");
		printlist(stack_a, stack_b);
	}
	
	/* TESTING INSTRUCTIONS */
	printf("\nSA:");
	sa(&stack_a, argc);
	printlist(stack_a, stack_b);
	
	printf("\nSB:");
	sb(&stack_b, argc);
	printlist(stack_a, stack_b);
	
	printf("\nSS:");
	ss(&stack_a, &stack_b, argc);
	printlist(stack_a, stack_b);
	
	printf("\nPA:");
	pa(&stack_a, &stack_b);
	printlist(stack_a, stack_b);

	// system("leaks a.out");
	return (0);
}


//TODO: change error message to "Error"!