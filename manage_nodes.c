/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:31:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/11 14:51:57 by rmazurit         ###   ########.fr       */
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

t_list	*ft_last_node(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
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
	tmp = ft_last_node(*lst); //set the pointer to the last node and assign the new element to the last node
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
	free(tmp->next);
	tmp->next = NULL;
}
