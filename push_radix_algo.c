/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_radix_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:21:00 by edalexan          #+#    #+#             */
/*   Updated: 2024/09/11 12:21:09 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_take_index_number(t_stack *stack)
{
	t_stack		*current;
	t_stack		*compare;
	int			k;

	current = stack;
	while (current != NULL)
	{
		k = 0;
		compare = stack;
		while (compare != NULL)
		{
			if (current->n > compare->n)
				k++;
			compare = compare->next;
		}
		current->index = k;
		current = current->next;
	}
}

void	ft_sort_b(t_stack **stack_a, t_stack **stack_b, int bit_s, int n)
{
	int	size_b;

	size_b = ft_stack_size(*stack_b);
	while (size_b > 0 && n <= bit_s && !ft_check_if_is_sorted(*stack_b))
	{
		if ((((*stack_b)->index >> n) & 1) == 0)
			ft_rb(stack_b, 1);
		else
			ft_pa(stack_a, stack_b);
		size_b--;
	}
	if (ft_check_if_is_sorted(*stack_b))
	{
		size_b = ft_stack_size(*stack_b);
		while (size_b > 0)
		{
			ft_pa(stack_a, stack_b);
			size_b--;
		}
	}
}

void	ft_sort_large(t_stack **stack_a, t_stack **stack_b)
{
	int	j;
	int	size;
	int	bit_size;

	size = ft_stack_size(*stack_a);
	bit_size = ft_bit_size(size);
	j = -1;
	while (++j <= bit_size)
	{
		size = ft_stack_size(*stack_a);
		while (size && !ft_check_if_is_sorted(*stack_a))
		{
			if ((((*stack_a)->index >> j) & 1) == 0)
				ft_pb(stack_a, stack_b);
			else
				ft_ra(stack_a, 1);
			size--;
		}
		ft_sort_b(stack_a, stack_b, bit_size, j + 1);
	}
	size = ft_stack_size(*stack_b);
	while (size--)
		ft_pa(stack_a, stack_b);
}

void	ft_the_action(t_stack *stack_a, int limit)
{
	t_stack	*stack_b;

	stack_b = NULL;
	ft_see_duplicates(stack_a);
	if (!ft_check_if_is_sorted(stack_a))
	{
		if (limit == 2)
			ft_sort_two(&stack_a);
		else if (limit == 3)
			ft_sort_three(&stack_a);
		else if (limit == 4)
			ft_sort_four(&stack_a, &stack_b);
		else if (limit == 5)
			ft_sort_five(&stack_a, &stack_b);
		else
		{
			ft_take_index_number(stack_a);
			ft_sort_large(&stack_a, &stack_b);
		}
	}
	ft_free_nodes(stack_a);
}
