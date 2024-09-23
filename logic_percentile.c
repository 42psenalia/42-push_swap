/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_percentile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:27:27 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/23 13:28:08 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	homerun(t_stack *b, int q100)
{
	while (b)
	{
		if (b->quartile == q100)
			return (false);
		b = b->next;
	}
	return (true);
}

void	logic_q100(t_stack **a, t_stack **b)
{
	int		q100;

	q100 = 100;
	while (*b && q100)
	{
		efficiency(b, 0);
		pb(b, a);
		if (homerun(*b, q100))
			q100--;
	}
	if (!*b)
		return ;
}
