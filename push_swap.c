/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:16:46 by rmazurit          #+#    #+#             */
/*   Updated: 2022/05/28 14:40:09 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_process_raw_args(int argc, char **argv, t_stack *stack_a, t_stack *tmp)
{
	int i;
	int	val;

	i = 1;
	while (i <= argc)
	{
		val = ft_atoi(argv[i]);
		tmp = create_new_node(val);
		insert_at_head(&stack_a, tmp);
		printf("%d\n", stack_a->nbr);
		i++;
	}
}

// void	ft_process_split_args(int argc, char **argv, t_stack *stack_a, t_stack *tmp)
// {

// }

t_stack	*ft_create_stack(int argc, char **argv, t_stack *stack_a, t_stack *tmp)
{
	if (argc >= 2)
		ft_process_raw_args(argc, argv, stack_a, tmp);
	// else if (argc == 2)
	// 	ft_process_split_args(argc, argv, stack_a, tmp);
	return (stack_a);
}

//include c files for testing purposes
#include "manage_nodes.c"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack	*stack_b;
	t_stack	*tmp;

	stack_a = NULL;
	stack_b = NULL;
	tmp = NULL;

	// argv[1] = "1";
	// argv[2] = "2";
	// argv[3] = "3";
	// argv[4] = "4";
	// argv[5] = "5";
	

	ft_create_stack(argc, argv, stack_a, tmp);
	// printlist(stack_a); //TODO: why it doesn't print!!!??
	
	return (0);
}

