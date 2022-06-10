/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:31:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/10 13:34:28 by rmazurit         ###   ########.fr       */
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
	tmp = ft_last_node(*lst);
	tmp->next = new;
}

void	printlist(t_list *stack) //TODO: rewrite without printf!
{
	t_list *tmp = stack;
	
	printf("\nSTACK A:\n");
	while (tmp->next != NULL)
	{
		printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->nbr);
}

