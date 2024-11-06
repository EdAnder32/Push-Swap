/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:16:49 by edalexan          #+#    #+#             */
/*   Updated: 2024/08/27 15:06:11 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	error(void)
{
	return (2147483649);
}

int	process_sign(const char *nptr, int *i)
{
	int	signal;

	signal = 1;
	while ((nptr[*i] >= 9 && nptr[*i] <= 13) || nptr[*i] == ' ')
		(*i)++;
	if (nptr[*i] == '+' || nptr[*i] == '-')
	{
		if (nptr[*i] == '-')
			signal = -1;
		(*i)++;
	}
	return (signal);
}

long	convert_to_number(const char *nptr, int i, int signal)
{
	long	number;

	number = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + (nptr[i] - '0');
		if ((signal == 1 && number > 2147483647)
			|| (signal == -1 && number > 2147483648))
			return (error());
		i++;
	}
	if (nptr[i])
		return (error());
	return (number * signal);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	int		signal;

	i = 0;
	signal = process_sign(nptr, &i);
	return (convert_to_number(nptr, i, signal));
}
