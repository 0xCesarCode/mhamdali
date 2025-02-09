/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:43:24 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/07 16:05:45 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

t_node	*create_node(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	push_front(t_node **head, int data)
{
	t_node	*node;

	node = create_node(data);
	if (!node)
		return ;
	node->next = *head;
	*head = node;
}

void	push_back(t_node **head, int data)
{
	t_node	*node;
	t_node	*temp;

	node = create_node(data);
	if (!node)
		return ;
	if (*head == NULL)
		*head = node;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
}

int	pop(t_node **head)
{
	t_node	*temp;
	int		value;

	if (!head || !*head)
		return (0);
	value = (*head)->data;
	temp = *head;
	*head = (*head)->next;
	free(temp);
	return (value);
}
