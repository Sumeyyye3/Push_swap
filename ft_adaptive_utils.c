/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 04:00:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/19 15:14:57 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
<<<<<<< HEAD

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
=======
>>>>>>> main

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
