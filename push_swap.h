/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:52:06 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/23 13:29:52 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	int				quartile;
	int				percentile;
	int				fin_pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/*-----------------------------------------------------------------------------
 *				Input Handlers
 *---------------------------------------------------------------------------*/

int		n_est(char const *s);
long	ft_atol(const char *str);
long	*mkrawset(char **argv, int size);
int		splitandadd(char *s, long *inputset, int n);
void	formstack(long *inputset, t_stack **stack, int size);
t_stack	*find_latest(t_stack *stack);
bool	setint(char const *argv);
bool	numfault(char const *argv);
bool	dupfault(long const *set, int size);
bool	intexceed(long const *set, int size);

/*-----------------------------------------------------------------------------
 *				Essentials
 *---------------------------------------------------------------------------*/

void	pushswap(t_stack **a, t_stack **b, int n);
void	logic_q4radix(t_stack **a, t_stack **b);
void	logic_q100(t_stack **a, t_stack **b);
void	logic_q4st(t_stack **a, t_stack **b, int q4);
void	partition(t_stack **a, t_stack **b, int q4);
void	efficiency(t_stack **stack, int n);
void	efficiency5(t_stack **a, t_stack **b, int n);
bool	reprise(long *ideal, t_stack *a);

/*-----------------------------------------------------------------------------
 *				Commands
 *---------------------------------------------------------------------------*/

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/*-----------------------------------------------------------------------------
 *				Utilities
 *---------------------------------------------------------------------------*/

long	identmin(long *array, int size);
long	identmax(long *array, int size);
long	*sortie(long *array, int size);
void	preset(long *sorted, t_stack **stack, int size);
int		errorinput(int size);
void	freestack(t_stack **stack);

#endif
