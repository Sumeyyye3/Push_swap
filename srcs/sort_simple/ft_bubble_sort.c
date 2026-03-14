/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumdogan <sumdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:00:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/14 02:07:53 by sumdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	ft_bubble_pass(t_stack **a, int size, t_bench *bench)
{
	int	i;
	int	swapped;

	i = 0;
	swapped = 0;
	while (i < size - 1)
	{
		if ((*a)->value > (*a)->next->value)
		{
			ft_sa(a, bench);
			swapped = 1;
		}
		ft_ra(a, bench);
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		ft_rra(a, bench);
		i++;
	}
	if (!swapped)
		return ;
}

void	ft_bubble_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	i;

	(void)b;
	if (!a || !*a || ft_is_sorted(*a))
		return ;
	size = ft_stack_size(*a);
	i = 0;
	while (i < size - 1 && !ft_is_sorted(*a))
	{
		ft_bubble_pass(a, size - i, bench);
		i++;
	}
}

void	ft_simple_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	min_pos;
	int	size;

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
			while (min_pos++ < size)
				ft_rra(a, bench);
		}
		ft_pb(a, b, bench);
	}
	while (*b)
		ft_pa(a, b, bench);
}
