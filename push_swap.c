/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:16:46 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/22 13:22:56 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (ft_create_stack(argc, argv, &stack_a) == false)
	{
		ft_delete_stack(&stack_a);
		return (1);
	}
	size = ft_list_size(stack_a);
	if (ft_stack_is_small(size) == true)
		ft_sort_small(&stack_a, &stack_b);
	else if (ft_stack_is_medium(size) == true || ft_stack_is_big(size) == true)
		ft_sort_big(&stack_a, &stack_b);
	ft_delete_stack(&stack_a);
	ft_delete_stack(&stack_b);
	return (0);
}
