/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:31:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/11 01:07:58 by rmazurit         ###   ########.fr       */
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

void	printlist(t_list *stack_a, t_list *stack_b) //TODO: rewrite without printf!
{
	t_list *tmp_a;
	t_list *tmp_b;
	
	if (!stack_a && !stack_b)
		return ;
	tmp_a = stack_a;
	tmp_b = stack_b;
	printf("\nSTACK A:	STACK B:\n");
	while (tmp_a->next != NULL)
	{
		if (tmp_a->next != NULL)
		{
			printf("%d", tmp_a->nbr);
			tmp_a = tmp_a->next;
		}
		if (tmp_b != NULL)
		{
			printf("		%d", tmp_b->nbr);
			tmp_b = tmp_b->next;
		}
		printf("\n");
	}
	printf("%d", tmp_a->nbr);
	if (tmp_b != NULL)
		printf("		%d", tmp_b->nbr);
	printf("\n");
}

