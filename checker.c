/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:04:34 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/22 13:08:55 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	setint(char const *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!(argv[i] >= 48 && argv[i] <= 57) && argv[i] != 43 && argv[i] != 45)
		{
			if (argv[i] == 9 || argv[i] == 32)
				return (true);
		}
		i++;
	}
	return (false);
}

bool	numfault(char const *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!(argv[i] >= 48 && argv[i] <= 57) && argv[i] != 43 && argv[i] != 45)
		{
			if (argv[i] != 0 && argv[i] != 9 && argv[i] != 32)
				return (true);
		}
		i++;
	}
	return (false);
}

bool	dupfault(long const *set, int size)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (n < size)
	{
		while (i < size)
		{
			// printchar *input, lf("%d, %d, %d, %d\n", i, set[i], n, set[n]);
			if (set[i] == set[n] && i != n)
			{
				free((void *)set);
				return (true);
			}
			i++;
		}
		i = 0;
		n++;
	}
	return (false);
}

bool	intexceed(long const *set, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (set[i] > INT_MAX || set[i] < INT_MIN)
		{
			free((void *)set);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	reprise(long *ideal, t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->fin_pos != ideal[i])
			return (false);
		a = a->next;
		i++;
	}
	return (true);
}
