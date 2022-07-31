/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_managers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:31:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/21 19:38:56 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 
	Create a new node with allocated memory, based on s_list structure (header).
	Assign the parameter 'value 'to the variable 'nbr'.
	Init. ’next’ to NULL. 
*/
t_list	*ft_new_node(int value)
{
	t_list	*result;

	result = malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->nbr = value;
	result->next = NULL;
	return (result);
}

/*
	Add the node to the end of the stack.
	If the list doesn't exist yet, initialize the list with the node,
	so the node becomes the first element of the stack.
*/
void	ft_add_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

/*
	Add the node to the beginning of the stack.
	If the list doesn't exist yet, initialize the list with the node,
	so the node becomes the first element of the stack.
*/
void	ft_add_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

/*
	Delete the last node in the stack (free the memory of the node).
*/
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

/*
	Free all the allocated memory of the stack.
*/
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
