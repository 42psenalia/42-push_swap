/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkrawset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:22:13 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/22 13:08:41 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	n_est(char const *s)
{
	int				count;
	int				mark;
	unsigned int	len;

	count = 0;
	mark = 0;
	len = 0;
	if (!s)
		return (0);
	while (s[len] || s[len] == '\0')
	{
		if (s[len] == 32 || s[len] == '\t' || s[len] == '\0')
		{
			if (len - mark > 0)
				count++;
			mark = len + 1;
		}
		if (s[len] == '\0')
			break ;
		len++;
	}
	return (count);
}

static char	*ft_substr(char const *s, int start, int len)
{
	int		size;
	char	*sub;

	if (!s)
		return (NULL);
	sub = malloc(sizeof(*s) * (len + 1));
	if (!sub)
		return (NULL);
	size = 0;
	while (s[start] && size < len)
	{
		sub[size] = s[start + size];
		size++;
	}
	sub[size] = '\0';
	return (sub);
}

int	splitandadd(char *s, long *inputset, int n)
{
	int		mark;
	int		len;
	char	*tobeconvert;

	mark = 0;
	len = 0;
	while (s[len] || s[len] == '\0')
	{
		if (s[len] == 32 || s[len] == 9 || s[len] == 0)
		{
			if (len - mark > 0)
			{
				tobeconvert = ft_substr(s, mark, len - mark);
				inputset[n] = ft_atol(tobeconvert);
				free(tobeconvert);
				n++;
			}
			mark = len + 1;
		}
		if (s[len] == '\0' || !inputset)
			break ;
		len++;
	}
	return (n);
}

long	*mkrawset(char **argv, int size)
{
	long	*inputset;
	int		i;
	int		n;

	i = 1;
	n = 0;
	inputset = malloc((sizeof(long) * (size + 1)));
	if (!inputset)
		return (NULL);
	while (argv[i])
	{
		if (setint(argv[i]))
			n = splitandadd(argv[i], inputset, n);
		else
			inputset[n++] = ft_atol(argv[i]);
		i++;
	}
	return (inputset);
}
