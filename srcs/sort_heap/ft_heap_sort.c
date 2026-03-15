/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumdogan <sumdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 04:00:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/15 05:56:52 by sumdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include<stdio.h>
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
	printf("once");
	while (*a)
	{
		max_pos = ft_get_max_pos(*a);
		ft_bring_to_top(a, max_pos, bench, 'a');
		ft_pb(a, b, bench);
	}
	printf("once");
	while (*b)
	{
		ft_pa(a, b, bench);
		if ((*a)->next && (*a)->value > (*a)->next->value)
			ft_sa(a, bench);
	}
	printf("once");
}
