/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_efficiency.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:10:15 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/23 13:27:51 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_max(t_stack *b)
{
	int		max;
	t_stack	*start;

	max = 0;
	start = b;
	while (b)
	{
		if (b->fin_pos > max)
			max = b->fin_pos;
		b = b->next;
	}
	b = start;
	while (b)
	{
		if (b->fin_pos == max)
			return (b);
		b = b->next;
	}
	return (NULL);
}

static void	efficiency3(t_stack **a)
{
	if ((*a)->fin_pos == 1 && (*a)->next->next->fin_pos == 2)
		rra(a);
	if ((*a)->fin_pos == 3 && (*a)->next->next->fin_pos == 1)
		ra(a);
	if ((*a)->fin_pos != 1 && (*a)->next->next->fin_pos == 3)
		sa(a);
	if ((*a)->fin_pos == 2 && (*a)->next->next->fin_pos == 1)
		rra(a);
	if ((*a)->fin_pos == 3 && (*a)->next->next->fin_pos == 2)
		ra(a);
	return ;
}

static int	efficiencyuod(t_stack *b, int uod)
{
	t_stack	*max;
	int		count;

	count = 0;
	max = find_max(b);
	if (uod == 0)
	{
		while (max->prev)
		{
			max = max->prev;
			count++;
		}
	}
	if (uod == 1)
	{
		while (max->next)
		{
			max = max->next;
			count++;
		}
	}
	return (count);
}

static void	efficiency100p(t_stack **b)
{
	t_stack	*max;

	if (!(*b)->next)
		return ;
	max = find_max(*b);
	if (efficiencyuod(*b, 0) > efficiencyuod(*b, 1))
	{
		while (*b != max)
			rrb(b);
	}
	else
	{
		while (*b != max)
			rb(b);
	}
	return ;
}

void	efficiency(t_stack **stack, int n)
{
	if (n == 2)
	{
		if ((*stack)->fin_pos != 1)
			sa(stack);
	}
	else if (n == 3)
		efficiency3(stack);
	else
		efficiency100p(stack);
	return ;
}
