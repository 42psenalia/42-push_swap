/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idealset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:52:37 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/22 13:53:47 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	identmin(long *array, int size)
{
	long	min;
	int		i;

	i = 0;
	min = array[i];
	while (i < size)
	{
		if (array[i] < min)
			min = (array[i]);
		i++;
	}
	return (min);
}

long	identmax(long *array, int size)
{
	long	max;
	int		i;

	i = 0;
	max = array[i];
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}

static void	relocate(long *sort, int input, int size)
{
	while (size > -1)
	{
		if (input < sort[size])
			sort[size + 1] = sort[size];
		else
		{
			sort[size + 1] = input;
			return ;
		}
		size--;
	}
	return ;
}

static void	rearrange(long *array, long *sort, int totali, int size)
{
	int	ia;
	int	is;

	ia = 0;
	is = 0;
	while (ia < size)
	{
		if (array[ia] > sort[0])
		{
			if (array[ia] > sort[is] && array[ia] < sort[totali])
			{
				is++;
				sort[is] = array[ia];
			}
			else
			{
				relocate(sort, array[ia], is);
				is++;
			}
		}
		ia++;
	}
	return ;
}

long	*sortie(long *array, int size)
{
	long	*sort;
	int		i;

	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
		i++;
	sort = (long *)malloc(sizeof(long) * size);
	if (!sort)
		return (NULL);
	sort[0] = identmin(array, size);
	sort[i] = identmax(array, size);
	rearrange(array, sort, i, size);
	free(array);
	return (sort);
}
