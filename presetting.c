/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presetting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:12:50 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/19 18:24:00 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	setfinpos(long *sorted, t_stack **stack, int size)
{
	int		i;
	t_stack	*a;
	t_stack	*start;

	i = 0;
	a = *stack;
	start = *stack;
	while (i < size)
	{
		while (a)
		{
			if (a->content == (int)sorted[i])
				a->fin_pos = i + 1;
			a = a->next;
		}
		a = start;
		i++;
	}
	return ;
}

static void	setq4(int size, t_stack	**stack)
{
	int		quartile;
	int		q;
	t_stack	*a;
	t_stack	*start;

	q = 4;
	a = *stack;
	start = *stack;
	while (q)
	{
		quartile = (size * q) / 4;
		while (a)
		{
			if (a->fin_pos <= quartile)
				a->quartile = q;
			a = a->next;
		}
		a = start;
		q--;
	}
	return ;
}

static void	setq100(int size, t_stack **stack)
{
	int		percent;
	int		p;
	t_stack	*a;
	t_stack	*start;

	p = 100;
	a = *stack;
	start = *stack;
	while (p)
	{
		percent = (size * p) / 100;
		while (a)
		{
			if (a->fin_pos <= percent)
				a->quartile = p;
			a = a->next;
		}
		a = start;
		p--;
	}
	return ;
}

void	preset(long *sorted, t_stack **stack, int size)
{
	if (!sorted || !stack || !size)
		return ;
	setfinpos(sorted, stack, size);
	if (size > 3)
		setq4(size, stack);
	if (size > 100)
		setq100(size, stack);
	return ;
}
