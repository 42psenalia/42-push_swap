/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_pushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:18:37 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/23 13:28:32 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static t_stack	*find_max(t_stack *b)
// {
// 	int		max;
//
// 	max = 0;
// 	while (b)
// 	{
// 		if (b->fin_pos > max)
// 			max = b->fin_pos;
// 		b = b->next;
// 	}
// 	while (b->prev)
// 		b = b->prev;
// 	while (b)
// 	{
// 		if (b->fin_pos == max)
// 			return (b);
// 		b = b->next;
// 	}
// 	return (NULL);
// }

static bool	homerun(t_stack *stack, int q4)
{
	while (stack)
	{
		if (stack->quartile == q4)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	partition(t_stack **a, t_stack **b, int q4)
{
	if (q4 == 4)
	{
		while (*b)
		{
			if ((*b)->quartile == 2 || (*b)->quartile == 1)
				pb(a, b);
			else
				break ;
		}
		return ;
	}
	while (!homerun(*a, q4))
	{
		rra(a);
		if ((*a)->quartile == q4)
			pa(a, b);
	}
	return ;
}

void	logic_q4st(t_stack **a, t_stack **b, int q4)
{
	while (*b && (*b)->quartile == q4)
	{
		efficiency(b, 0);
		pb(a, b);
	}
	return ;
}
