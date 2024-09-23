/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrotor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:20:34 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/23 13:31:13 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	revrotate(t_stack **stack)
{
	t_stack	*latest;

	if (!stack || !*stack || !(*stack)->next)
		return (false);
	latest = find_latest(*stack);
	latest->prev->next = NULL;
	latest->next = *stack;
	latest->prev = NULL;
	*stack = latest;
	latest->next->prev = latest;
	if (latest->prev || !latest->next)
		return (false);
	return (true);
}

void	rra(t_stack **a)
{
	if (revrotate(a))
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	if (revrotate(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	bool	rva;
	bool	rvb;

	rva = revrotate(a);
	rvb = revrotate(b);
	if (rva && rvb)
		write(1, "rrr\n", 4);
	else if (rva)
		write(1, "rra\n", 4);
	else if (rvb)
		write(1, "rrb\n", 4);
	else
		exit(EXIT_FAILURE);
}
