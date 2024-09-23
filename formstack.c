/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formstack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:50:21 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/19 18:00:03 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_latest(t_stack *stack)
{
	t_stack	*temp;

	if (stack == NULL)
		return (NULL);
	temp = stack;
	while (temp && temp->next)
		temp = temp->next;
	return (temp);
}

static void	nodeconnect(t_stack **stack, t_stack *node)
{
	t_stack	*latest;

	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		latest = find_latest(*stack);
		latest->next = node;
		node->prev = latest;
	}
	return ;
}

void	formstack(long *inputset, t_stack **stack, int size)
{
	t_stack	*node;
	int		i;

	if (!stack || !inputset)
		return ;
	i = 0;
	while (i < size)
	{
		node = malloc(sizeof(t_stack));
		if (node == NULL)
			return ;
		node->content = (int)inputset[i];
		node->next = NULL;
		nodeconnect(stack, node);
		i++;
	}
	return ;
}
