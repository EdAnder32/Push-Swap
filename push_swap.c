/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:53:48 by edalexan          #+#    #+#             */
/*   Updated: 2024/09/11 11:50:40 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack **stack)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	if ((*stack)->n > (*stack)->next->n)
		ft_sa(stack, 1);
}

void	ft_sort_three_two(int pos, t_stack **stack)
{
	if (pos == 1)
	{
		ft_ra(stack, 1);
		if ((*stack)->n > (*stack)->next->n)
			ft_sa(stack, 1);
	}
	else if (pos == 2)
	{
		ft_rra(stack, 1);
		if ((*stack)->n > (*stack)->next->n)
			ft_sa(stack, 1);
	}
	else if (pos == 3)
	{
		if ((*stack)->n > (*stack)->next->n)
			ft_sa(stack, 1);
	}
}

void	ft_sort_three(t_stack **stack)
{
	t_stack		*current;
	int			big;
	int			pos;
	int			i;

	if (stack == NULL)
		return ;
	current = (*stack);
	big = current->n;
	i = 1;
	pos = 1;
	while (current != NULL)
	{
		if (current->n > big)
		{
			big = current->n;
			pos = i;
		}
		i++;
		current = current->next;
	}
	ft_sort_three_two(pos, stack);
}

int	ft_only_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (ac < 2)
	{
		free(stack_a);
		return (0);
	}
	if (ac == 2)
		ft_arg_is_str(av, stack_a);
	else if (ac > 2)
		ft_arg_is_arg(ac, av, stack_a);
	ft_free_nodes(stack_a);
}
