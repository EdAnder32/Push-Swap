/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:16:16 by edalexan          #+#    #+#             */
/*   Updated: 2024/08/27 15:02:48 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_matrix(char **matrix)
{
	int	k;
	int	x;

	k = 0;
	while (matrix[k])
	{
		x = 0;
		while (matrix[k][x])
		{
			ft_printf("%c", matrix[k][x]);
			x++;
		}
		ft_printf("\n");
		k++;
	}
}
