/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushtop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:02:23 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/23 13:31:00 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	pushtop(t_stack **from, t_stack **to)
{
	t_stack	*relocate;

	if (*from == NULL)
		return (false);
	relocate = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	relocate->prev = NULL;
	if (*to == NULL)
	{
		*to = relocate;
		relocate->next = NULL;
	}
	else
	{
		relocate->next = *to;
		relocate->next->prev = relocate;
		(*to) = relocate;
	}
	if ((*to)->prev)
		return (false);
	return (true);
}

void	pa(t_stack **a, t_stack **b)
{
	if (pushtop(a, b))
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	if (pushtop(b, a))
		write(1, "pb\n", 3);
}
