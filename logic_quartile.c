/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_quartile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:07:16 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/23 13:28:56 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	homerun1(t_stack *stack)
{
	while (stack)
	{
		if (stack->quartile == 1 || stack->quartile == 4)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static bool	homerun2(t_stack *stack)
{
	while (stack)
	{
		if (stack->quartile == 2)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static void	q4radix2(t_stack **a, t_stack **b)
{
	while ((*a)->next)
	{
		if ((*a)->quartile == 2)
			pa(a, b);
		else
			ra(a);
		if (homerun2(*a))
			break ;
	}
}

void	logic_q4radix(t_stack **a, t_stack **b)
{
	while ((*a)->next)
	{
		if ((*a)->quartile == 1 || (*a)->quartile == 4)
		{
			pa(a, b);
			if ((*b)->quartile == 4 && (*b)->next->quartile == 1)
				sb(b);
		}
		else
			ra(a);
		if (homerun1(*a))
			break ;
	}
	q4radix2(a, b);
}
