/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ad                                   +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 04:00:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/15 05:52:54 by sumdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<stdio.h>
static void	ft_dispatch_simple(t_stack **a, t_stack **b, t_bench *bench)
{
	bench->strategy = "Bubble Sort";
	bench->complexity = "O(n²)";
	ft_bubble_sort(a, b, bench);
}

static void	ft_dispatch_medium(t_stack **a, t_stack **b, t_bench *bench)
{
	bench->strategy = "Block Sort";
	bench->complexity = "O(n√n)";
	ft_block_sort(a, b, bench);
}

static void	ft_dispatch_complex(t_stack **a, t_stack **b, t_bench *bench)
{
	bench->strategy = "Heap Sort";
	bench->complexity = "O(n log n)";
	ft_heap_sort(a, b, bench);
}

// void	ft_dispatch_sort(t_stack **a, t_stack **b, char *strat, t_bench *bch)
// {
// 	if (ft_strcmp(strat, "simple") == 0)
// 	{
// 		ft_dispatch_simple(a, b, bch);
// 	}
// 	else if (ft_strcmp(strat, "medium") == 0)
// 	{
// 		ft_dispatch_medium(a, b, bch);
// 	}
// 	else
// 		ft_dispatch_complex(a, b, bch);
// }

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
			ftaptive_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumdogan <sumdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*             _simple_sort(a, b, bch);
			return ;
		}
	}
	ft_dispatch_complex(a, b, strat, bch);
}
