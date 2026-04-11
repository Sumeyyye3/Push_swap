/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_block_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/04/10 23:08:55 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_four(t_stack **a, t_stack **b, t_bench *bench)
{
	(void)b;
	ft_move_min_top(a, bench);
	ft_pb(a, b, bench);
	ft_tiny_fix(a, bench);
	ft_pa(a, b, bench);
}

void	ft_sort_four_and_five(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;

	size = ft_stack_size(*a);
	if (size <= 3)
		return ;
	ft_set_bench(bench, 4);
	if (size == 4)
		ft_sort_four(a, b, bench);
	else if (size == 5)
	{
		ft_move_min_top(a, bench);
		ft_pb(a, b, bench);
		ft_sort_four(a, b, bench);
		ft_pa(a, b, bench);
	}
}

int	ft_find_in_chunk(t_stack *stack, int min, int max)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index >= min && stack->index <= max)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

static int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (1);
	i = 1;
	while (i * i <= nb)
		i++;
	return (i - 1);
}

void	ft_block_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	block;
	int	range[2];
	int	i;

	if (!a || !*a || ft_is_sorted(*a))
		return ;
	size = ft_stack_size(*a);
	block = ft_sqrt(size);
	if (block < 1)
		block = 1;
	i = 0;
	while (i < (size + block - 1) / block)
	{
		range[0] = i * block;
		range[1] = range[0] + block - 1;
		ft_push_chunk(a, b, range, bench);
		i++;
	}
	while (*b)
	{
		ft_optimize_b(b, bench);
		ft_pa(a, b, bench);
	}
}
