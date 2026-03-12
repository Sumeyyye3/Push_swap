/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 04:00:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/13 01:50:35 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	ft_rotate_up(t_stack **stack, int pos, t_bench *bench, char name)
{
	while (pos-- > 0)
	{
		if (name == 'a')
			ft_ra(stack, bench);
		else
			ft_rb(stack, bench);
	}
}

void	ft_bring_to_top(t_stack **stack, int pos, t_bench *bench, char name)
{
	int	size;

	if (!stack || !*stack)
		return ;
	size = ft_stack_size(*stack);
	if (pos <= size / 2)
		ft_rotate_up(stack, pos, bench, name);
	else
	{
		if (name == 'a')
		{
			while (pos++ < size)
				ft_rra(stack, bench);
		}
		else
		{
			while (pos++ < size)
				ft_rrb(stack, bench);
		}
	}
}

void	ft_heap_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	max_pos;

	if (!a || !*a || ft_is_sorted(*a))
		return ;
	while (*a)
	{
		max_pos = ft_get_max_pos(*a);
		ft_bring_to_top(a, max_pos, bench, 'a');
		ft_pb(a, b, bench);
	}
	while (*b)
	{
		ft_pa(a, b, bench);
		if ((*a)->next && (*a)->value > (*a)->next->value)
			ft_sa(a, bench);
	}
}
