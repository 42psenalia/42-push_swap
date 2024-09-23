/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_efficiency5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:40:59 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/22 14:06:38 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	homerun(t_stack *stack)
{
	while (stack)
	{
		if (stack->quartile == 1 || stack->quartile == 2)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static void	n5_q4radix(t_stack **a, t_stack **b)
{
	while (*a)
	{
		if ((*a)->quartile == 1 || (*a)->quartile == 2)
		{
			pa(a, b);
			if ((*b)->quartile != 2 && (*b)->next)
				sb(b);
		}
		else
			ra(a);
		if (homerun(*a))
			break ;
	}
	return ;
}

void	efficiency5(t_stack **a, t_stack **b, int n)
{
	n5_q4radix(a, b);
	if (n == 4)
	{
		if ((*a)->fin_pos != 3)
			sa(a);
	}
	else if (n == 5)
	{
		if ((*a)->fin_pos == 3 && (*a)->next->next->fin_pos == 4)
			rra(a);
		if ((*a)->fin_pos == 5 && (*a)->next->next->fin_pos == 3)
			ra(a);
		if ((*a)->fin_pos != 3 && (*a)->next->next->fin_pos == 5)
			sa(a);
		if ((*a)->fin_pos == 4 && (*a)->next->next->fin_pos == 3)
			rra(a);
		if ((*a)->fin_pos == 5 && (*a)->next->next->fin_pos == 4)
			ra(a);
	}
	while (*b)
		pb(a, b);
	return ;
}
