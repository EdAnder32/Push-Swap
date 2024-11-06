/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort_some.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:43:19 by edalexan          #+#    #+#             */
/*   Updated: 2024/09/11 13:43:28 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_values(int *tmp, int *times, t_stack *current)
{
	int	i;

	i = 0;
	while (current)
	{
		if (*tmp > current->n)
		{
			*tmp = current->n;
			*times = i;
		}
		i++;
		current = current->next;
	}
}

void	ft_find_min(t_stack **stack_a, t_stack **stack_b, t_stack *current)
{
	int	times;
	int	tmp;
	int	size;

	size = ft_stack_size(*stack_a);
	times = 0;
	tmp = current->n;
	ft_find_values(&tmp, &times, current);
	if (times <= size / 2)
	{
		while (times--)
			ft_ra(stack_a, 1);
	}
	else
	{
		times = size - times;
		while (times--)
			ft_rra(stack_a, 1);
	}
	ft_pb(stack_a, stack_b);
}

void	ft_sort_four(t_stack **stack_a, t_stack	**stack_b)
{
	t_stack		*current;

	current = *stack_a;
	ft_find_min(stack_a, stack_b, current);
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*current;

	current = *stack_a;
	ft_find_min(stack_a, stack_b, current);
	current = *stack_a;
	ft_find_min(stack_a, stack_b, current);
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	if ((*stack_a)->n > (*stack_a)->next->n)
		ft_ra(stack_a, 1);
}
