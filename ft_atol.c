/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:43:11 by psenalia          #+#    #+#             */
/*   Updated: 2024/08/12 15:50:04 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	output;
	int		negative;

	output = 0;
	negative = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		output = (output * 10) + *str - 48;
		str++;
	}
	return (output * negative);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	long	output;

	if (argc != 2)
		return (0);
	output = ft_atol(argv[1]);
	if (output > INT_MAX || output < INT_MIN)
		return (printf("Error: int overflow\n"));
	else
		printf("%d\n", (int)output);
}*/
