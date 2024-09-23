/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:33:24 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/23 13:30:42 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	rotate(t_stack **stack)
{
	t_stack	*latest;

	if (!stack || !*stack || !(*stack)->next)
		return (false);
	latest = find_latest(*stack);
	latest->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	latest->next->prev = latest;
	latest->next->next = NULL;
	if (latest->next->next || !latest->next->prev)
		return (false);
	return (true);
}

void	ra(t_stack **a)
{
	if (rotate(a))
		write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	if (rotate(b))
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	bool	roa;
	bool	rob;

	roa = rotate(a);
	rob = rotate(b);
	if (roa && rob)
		write(1, "rr\n", 3);
	else if (roa)
		write(1, "ra\n", 3);
	else if (rob)
		write(1, "rb\n", 3);
	else
		exit(EXIT_FAILURE);
}
