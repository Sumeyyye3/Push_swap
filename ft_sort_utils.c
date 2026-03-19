/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:31:12 by mozay             #+#    #+#             */
/*   Updated: 2026/03/19 15:15:50 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack **a, t_bench *bench)
{
	if ((*a)->value > (*a)->next->value)
		ft_sa(a, bench);
}

void	ft_bring_min_to_top(t_stack **a, int pos, t_bench *bench)
{
	int	size;

	size = ft_stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ft_ra(a, bench);
	}
	else
	{
		while (pos++ < size)
			ft_rra(a, bench);
	}
}
