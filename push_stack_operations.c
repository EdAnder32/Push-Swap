/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 08:32:57 by edalexan          #+#    #+#             */
/*   Updated: 2024/08/30 09:28:51 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int n)
{
	t_stack		*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->n = n;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_add_to_stack(t_stack **head, int n)
{
	t_stack		*node;

	node = create_node(n);
	if (!node)
		return ;
	node->next = *head;
	if (*head != NULL)
		(*head)->prev = node;
	*head = node;
}
