/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:31:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/05/28 12:50:24 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_stack *head) //TODO: rewrite without printf!
{
	t_stack *temporary = head;
	while (temporary != NULL)
	{
		printf("%d\n", temporary->nbr);
		temporary = temporary->next;
	}
}
t_stack 	*create_new_node(int value)
{
	t_stack *result = malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	result->nbr = value;
	result->next = NULL;
	return (result);
}

void	insert_at_head(t_stack **head, t_stack *node_to_insert)
{
	node_to_insert->next = *head;
	*head = node_to_insert;
}

void	insert_after_node(t_stack *node_to_insert_after, t_stack *newnode)
{
	newnode->next = node_to_insert_after->next;
	node_to_insert_after->next = newnode;
}