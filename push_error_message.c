/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_error_message.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 08:06:19 by edalexan          #+#    #+#             */
/*   Updated: 2024/08/30 08:27:32 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_nodes(t_stack *stack)
{
	t_stack	*current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}

void	ft_error_message_two(int n, char **matrix, t_stack *stack)
{
	if (n == 4)
	{
		write (2, "Error\n", 6);
		if (matrix)
			ft_free_matrix(matrix);
		if (stack)
			free(stack);
		exit(1);
	}
	if (n == 5)
	{
		ft_free_matrix(matrix);
		ft_free_nodes(stack);
		write (2, "Error\n", 6);
		exit(1);
	}
}

void	ft_error_message(int n, char **matrix, t_stack *stack)
{
	if (n == 1)
	{
		write (2, "Error\n", 6);
		if (matrix)
			ft_free_matrix(matrix);
		if (stack)
			free(stack);
		exit(1);
	}
	if (n == 2)
	{
		ft_free_nodes(stack);
		write (2, "Error\n", 6);
		exit(1);
	}
	if (n == 3)
	{
		free(stack);
		if (matrix)
			ft_free_matrix(matrix);
		write (2, "Error\n", 6);
		exit(1);
	}
	else
		ft_error_message_two(n, matrix, stack);
}
