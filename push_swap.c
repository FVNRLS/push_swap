/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:16:46 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/10 23:11:03 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list 	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	
	if (ft_create_stack(argc, argv, &stack_a) == false)
		return (1);
	else if (ft_duplicates_found(stack_a) == true)
		return (1);
	else
		printlist(stack_a);
	

	/* TESTING INSTRUCTIONS */
	printf("\nSA:\n");
	sa(&stack_a, argc);
	printlist(stack_a);
	
	printf("\nSB:\n");
	sb(&stack_b, argc);
	printlist(stack_b);
	
	printf("\nSS:\n");
	sb(&stack_b, argc);
	printlist(stack_a);
	printlist(stack_b);
	
	// system("leaks a.out");
	return (0);
}


//TODO: change error message to "Error"!