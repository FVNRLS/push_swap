/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:31:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/12 14:24:16 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_new_node(int value)
{
	t_list *result = malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->nbr = value;
	result->next = NULL;
	return (result);
}

void	ft_add_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	if (!*lst) //very important!! protection against segfault - initializing the first element of the stack
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	// tmp = ft_last_node(*lst); //set the pointer to the last node and assign the new element to the last node
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_add_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

void	ft_del_last(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->nbr = 0;
	free(tmp->next);
	tmp->next = NULL;
}

void	ft_delete_stack(t_list **stack)
{
	t_list	*tmp;

	if ((!stack) || (!*stack))
		return ;
	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
