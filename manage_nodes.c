/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:31:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/05/28 18:01:25 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_list *head) //TODO: rewrite without printf!
{
	t_list *temporary = head;
	while (temporary != NULL)
	{
		printf("%d\n", temporary->nbr);
		temporary = temporary->next;
	}
}
t_list 	*create_new_node(int value)
{
	t_list *result = malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->nbr = value;
	result->next = NULL;
	return (result);
}

void	insert_at_head(t_list **head, t_list *node_to_insert)
{
	node_to_insert->next = *head;
	*head = node_to_insert;
}

void	insert_after_node(t_list *node_to_insert_after, t_list *newnode)
{
	newnode->next = node_to_insert_after->next;
	node_to_insert_after->next = newnode;
}