/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumdogan <sumdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 04:00:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/15 05:52:54 by sumdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_dispatch_complex(t_stack **a, t_stack **b, t_bench *bench)
{
	bench->strategy = "Radix Sort";
	bench->complexity = "O(n * k)";
	ft_radix_sort(a, b, bench);
}

void	ft_sort_stacks(t_stack **a, t_stack **b, char *strat, t_bench *bch)
{
	int	size;

	if (!a || !*a)
		return ;
	size = ft_stack_size(*a);
	if(ft_strcmp(strat, "none") == 0)
	{
		if (size <= 1 || ft_is_sorted(*a))
			return ;
		if (size == 2)
		{
			ft_sort_two(a, bch);
			return ;
		}
		if (size <= 5)
		{
			ft_simple_sort(a, b, bch);
			return ;
		}
	}
	ft_dispatch_complex(a, b, bch);
}
