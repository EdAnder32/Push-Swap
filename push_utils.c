/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 08:01:09 by edalexan          #+#    #+#             */
/*   Updated: 2024/08/30 08:20:33 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isalnum_update(char	*str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_stack_size(t_stack *stack)
{
	t_stack		*current;
	int			i;

	i = 0;
	current = stack;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int	ft_bit_size(int size)
{
	int	bit_size;

	bit_size = 0;
	while (size > 1 && ++bit_size)
		size = size / 2;
	return (bit_size);
}

int	ft_check_if_is_sorted(t_stack *stack)
{
	t_stack		*current;

	if (stack == NULL)
		return (1);
	current = stack;
	while (current->next != NULL)
	{
		if (current->n > current->next->n)
			return (0);
		current = current->next;
	}
	return (1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	write (1, "rrr\n", 4);
}
