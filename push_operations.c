/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:14:57 by edalexan          #+#    #+#             */
/*   Updated: 2024/09/11 12:15:07 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*tmp;

	if ((*stack_a) == NULL)
		return ;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	write (1, "pb\n", 3);
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*tmp;

	if ((*stack_b) == NULL)
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	write (1, "pa\n", 3);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_sa(stack_a, 1);
	ft_sb(stack_b, 1);
	write (1, "ss\n", 3);
}

void	ft_sb(t_stack **stack_b, int stop)
{
	t_stack		*tmp;

	if ((*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	if (stop)
		write (1, "sb\n", 3);
}

void	ft_sa(t_stack **stack_a, int stop)
{
	int		tmp;

	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a)->n;
	(*stack_a)->n = (*stack_a)->next->n;
	(*stack_a)->next->n = tmp;
	if (stop)
		write(1, "sa\n", 3);
}
