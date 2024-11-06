/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_verifications.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:57:02 by edalexan          #+#    #+#             */
/*   Updated: 2024/09/11 11:50:45 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_see_duplicates(t_stack *stack)
{
	t_stack		*current;
	t_stack		*verificate;

	current = stack;
	while (current != NULL)
	{
		verificate = current->next;
		while (verificate != NULL)
		{
			if (current->n == verificate->n)
				ft_error_message(2, NULL, stack);
			verificate = verificate->next;
		}
		current = current->next;
	}
}

void	ft_get_number_from_matrix(char **matrix, t_stack *stack)
{
	int		size;
	int		limit;
	long	num;

	size = 0;
	while (matrix[size])
	{
		if (ft_isalnum_update(matrix[size]))
			size++;
		else
			ft_error_message(1, matrix, stack);
	}
	limit = size;
	size--;
	while (size >= 0)
	{
		num = ft_atoi(matrix[size]);
		if (num == 2147483649)
			ft_error_message(5, matrix, stack);
		else
			ft_add_to_stack(&stack, num);
		size--;
	}
	ft_free_matrix(matrix);
	ft_the_action(stack, limit);
}

int	ft_only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

void	ft_arg_is_str(char **av, t_stack *stack)
{
	char	**matrix;

	if (!av[1][0] || ft_only_space(av[1]) || ft_only_num(av[1]))
		ft_error_message(2, NULL, stack);
	else if (ft_only_space(av[1]))
		ft_error_message(2, NULL, stack);
	else
	{
		matrix = ft_split(av[1]);
		ft_get_number_from_matrix(matrix, stack);
	}
}

void	ft_arg_is_arg(int ac, char **av, t_stack *stack)
{
	int		i;
	int		limit;
	long	num;

	i = 1;
	while (i <= ac - 1)
	{
		num = ft_atoi(av[i]);
		if (num == 2147483649)
			ft_error_message(4, NULL, stack);
		if ((ft_isalnum_update(av[i])) && (num <= 2147483647))
			i++;
		else
			ft_error_message(4, NULL, stack);
	}
	i--;
	limit = i;
	while (i > 0)
	{
		ft_add_to_stack(&stack, ft_atoi(av[i]));
		i--;
	}
	ft_the_action(stack, limit);
}
