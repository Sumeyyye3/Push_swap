/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_block_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/19 15:15:05 by mozay            ###   ########.fr       */
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

int	ft_sqrt(int nb)
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
	int	cnt;
	int	i;
	int	min;

	if (!a || !*a || ft_is_sorted(*a))
		return ;
	size = ft_stack_size(*a);
	block = ft_sqrt(size);
	if (block < 1)
		block = 1;
	cnt = (size + block - 1) / block;
	i = 0;
	while (i < cnt)
	{
		min = i * block;
		ft_push_chunk(a, b, min, min + block - 1,bench);
		i++;
	}
	while (*b)
	{
		ft_optimize_b(b, bench);
		ft_pa(a, b, bench);
	}
}
