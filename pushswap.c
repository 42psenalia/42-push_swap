/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:05:39 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/23 12:52:47 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushswap(t_stack **a, t_stack **b, int n)
{
	int	q4;

	if (n <= 3)
	{
		efficiency(a, n);
		return ;
	}
	if (n > 3 && n <= 5)
	{
		efficiency5(a, b, n);
		return ;
	}
	if (n > 5)
		logic_q4radix(a, b);
	q4 = 4;
	while (q4)
	{
		partition(a, b, q4);
		if (n > 100)
			logic_q100(a, b);
		else
			logic_q4st(a, b, q4);
		q4--;
	}
}
