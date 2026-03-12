/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_block_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/13 00:49:48 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	ft_rotate_to_pos(t_stack **a, int pos, t_bench *bench)
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

void	ft_push_chunk(t_stack **a, t_stack **b, int min, int max)
{
	int		pos;
	t_bench	*bench;

	bench = NULL;
	while (1)
	{
		pos = ft_find_in_chunk(*a, min, max);
		if (pos == -1)
			break ;
		ft_rotate_to_pos(a, pos, bench);
		ft_pb(a, b, bench);
	}
}

void	ft_optimize_b(t_stack **b, t_bench *bench)
{
	int	max_pos;
	int	size;

	if (!b || !*b || !(*b)->next)
		return ;
	size = ft_stack_size(*b);
	max_pos = ft_get_max_pos(*b);
	if (max_pos <= size / 2)
	{
		while (max_pos-- > 0)
			ft_rb(b, bench);
	}
	else
	{
		while (max_pos++ < size)
			ft_rrb(b, bench);
	}
}
