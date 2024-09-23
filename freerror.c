/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:55:28 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/19 18:31:30 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	errorinput(int size)
{
	if (size < 0)
		return (write(1, "Error: Can only take integers\n", 30));
	else
		return (write(1, "Error: No duplicates or int overflow allowed\n", 46));
}

// void	freestack(t_stack **a)
// {
// 	t_stack	*temp;
// 	t_stack	*current;
//
// 	if (!a)
// 		return ;
// 	current = *a;
// 	while (current)
// 	{
// 		temp = current->next;
// 		free(current);
// 		current = temp;
// 	}
// 	*a = NULL;
// 	return ;
// }
