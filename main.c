/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:19:57 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/23 13:30:02 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	countsize(char **argv)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	while (argv[i])
	{
		if (numfault(argv[i]))
			return (-1);
		if (setint(argv[i]))
			n += n_est(argv[i]);
		else
			n++;
		i++;
	}
	return (n);
}

void	freestack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	while ((*stack)->prev)
		*stack = (*stack)->prev;
	while (*stack)
	{
		printf("%d	", (*stack)->content);
		temp = (*stack)->next;
		free(*stack);
		printf("freed\n");
		*stack = temp;
	}
	*stack = NULL;
	return ;
}

int	main(int argc, char **argv)
{
	long	*inputset;
	t_stack	*a;
	t_stack	*b;
	int		n;
	// int		i;
	// t_stack	*temp;

	a = NULL;
	b = NULL;
	n = countsize(argv);
	// printf("%d\n", n);
	// printf("%lu\n", sizeof(t_stack));
	if (argc == 1 || n == 1)
		return (0);
	else if (n < 0)
		return (errorinput(n));
	inputset = mkrawset(argv, n);
	if (dupfault(inputset, n) || intexceed(inputset, n))
		return (errorinput(n));
	// i = 0;
	// while (i < n)
	// {
	// 	if (i + 1 < n)
	// 		printf("%ld, ", inputset[i]);
	// 	else
	// 		printf("%ld\n", inputset[i]);
	// 	i++;
	// }
	formstack(inputset, &a, n);
	inputset = sortie(inputset, n);
	// i = 0;
	// while (i < n)
	// {
	// 	if (i + 1 < n)
	// 		printf("%ld, ", inputset[i]);
	// 	else
	// 		printf("%ld\n", inputset[i]);
	// 	i++;
	// }
	preset(inputset, &a, n);
	// temp = a;
	// while (a)
	// {
	// 	printf("%d	[%d]	[q%d]	[p%d]\n", \
	// 		a->content, a->fin_pos, a->quartile, a->percentile);
	// 	if (!a->next)
	// 		break ;
	// 	a = a->next;
	// }
	// a = temp;
	if (!reprise(inputset, a))
		pushswap(&a, &b, n);
	// while (a)
	// {
	// 	printf("%d	[%d]	[q%d]	[p%d]\n", \
	// 		a->content, a->fin_pos, a->quartile, a->percentile);
	// 	if (!a->next)
	// 		break ;
	// 	a = a->next;
	// }
	// a = temp;
	freestack(&a);
	printf("stack freed\n");
	free(inputset);
	printf("int array freed\n");
	return (0);
}
