/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaptop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:34:34 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/22 13:38:49 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	swaptop(t_stack **stack)
{
	if (*stack == NULL || stack == NULL)
		return (false);
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
	return (true);
}

void	sa(t_stack **a)
{
	if (swaptop(a))
		write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	if (swaptop(b))
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	bool	swa;
	bool	swb;

	swa = swaptop(a);
	swb = swaptop(b);
	if (swa && swb)
		write(1, "ss\n", 3);
	else if (swa)
		write(1, "sa\n", 3);
	else if (swb)
		write(1, "sb\n", 3);
	else
		exit(EXIT_FAILURE);
}
