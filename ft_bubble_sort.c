/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:00:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/29 23:51:32 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_sort_two(t_stack **a, t_bench *bench)
{
	if ((*a)->value > (*a)->next->value)
		ft_sa(a, bench);
}

void	ft_simple_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	min_pos;
	int	size;
	int	moves;

	while (*a)
	{
		size = ft_stack_size(*a);
		min_pos = ft_get_min_pos(*a);
		if (min_pos <= size / 2)
		{
			while (min_pos-- > 0)
				ft_ra(a, bench);
		}
		else
		{
			moves = size - min_pos;
			while (moves-- > 0)
				ft_rra(a, bench);
		}
		ft_pb(a, b, bench);
	}
	while (*b)
		ft_pa(a, b, bench);
}
