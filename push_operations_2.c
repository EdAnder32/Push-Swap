/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:16:31 by edalexan          #+#    #+#             */
/*   Updated: 2024/09/11 12:16:40 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb(t_stack **stack_b, int stop)
{
	t_stack		*last;
	t_stack		*second_last;

	if ((*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	last = (*stack_b);
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = (*stack_b);
	(*stack_b) = last;
	if (stop)
		write (1, "rrb\n", 4);
}

void	ft_rra(t_stack **stack, int stop)
{
	t_stack		*last;
	t_stack		*second_last;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	last = (*stack);
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = (*stack);
	(*stack) = last;
	if (stop)
		write (1, "rra\n", 4);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	write (1, "rr\n", 3);
}

void	ft_rb(t_stack **stack_b, int stop)
{
	t_stack		*last;
	t_stack		*tmp;

	if ((*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b);
	last = (*stack_b);
	while (last->next)
		last = last->next;
	(*stack_b) = tmp->next;
	tmp->next = NULL;
	last->next = tmp;
	if (stop)
		write(1, "rb\n", 3);
}

void	ft_ra(t_stack **stack_a, int stop)
{
	t_stack		*last;
	t_stack		*tmp;

	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a);
	last = (*stack_a);
	while (last->next)
		last = last->next;
	(*stack_a) = tmp->next;
	tmp->next = NULL;
	last->next = tmp;
	if (stop)
		write(1, "ra\n", 3);
}
