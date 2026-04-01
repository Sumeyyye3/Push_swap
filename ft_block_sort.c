/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_block_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/04/02 00:55:17 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
