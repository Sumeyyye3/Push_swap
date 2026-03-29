/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/03/30 00:57:09 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_set_bench(t_bench *bch, int type)
{
	if (type == 1)
	{
		bch->strategy = "Simple";
		bch->complexity = "O(n^2)";
	}
	else if (type == 2)
	{
		bch->strategy = "Medium";
		bch->complexity = "O(n*sqrt(n))";
	}
	else if (type == 3)
	{
		bch->strategy = "Complex";
		bch->complexity = "O(n log n)";
	}
	else
	{
		bch->strategy = "Adaptive";
		bch->complexity = "O(n^2) to O(n log n)";
	}
}

static int	ft_is_almost_sorted(t_stack *a)
{
	int	errors;

	errors = 0;
	while (a && a->next)
	{
		if (a->value > a->next->value)
			errors++;
		a = a->next;
	}
	return (errors <= 2);
}

static void	ft_tiny_fix(t_stack **a, t_bench *bench)
{
	if ((*a)->value > (*a)->next->value)
		ft_sa(a, bench);
	else
	{
		ft_ra(a, bench);
		if ((*a)->value > (*a)->next->value)
			ft_sa(a, bench);
		ft_rra(a, bench);
	}
}

void	ft_adaptive_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	double	disorder;

	if (ft_is_almost_sorted(*a))
	{
		ft_set_bench(bench, 1);
		ft_tiny_fix(a, bench);
		return ;
	}
	disorder = ft_compute_disorder(*a);
	if (disorder < 0.2)
	{
		ft_set_bench(bench, 1);
		ft_simple_sort(a, b, bench);
	}
	else if (disorder < 0.5)
	{
		ft_set_bench(bench, 2);
		ft_block_sort(a, b, bench);
	}
	else
	{
		ft_set_bench(bench, 3);
		ft_radix_sort(a, b, bench);
	}
}

void	ft_sort_stacks(t_stack **a, t_stack **b, char *strat, t_bench *bch)
{
	if (!a || !*a || ft_is_sorted(*a))
		return ;
	if (ft_stack_size(*a) == 2)
	{
		ft_sort_two(a, bch);
		return ;
	}
	if (ft_strcmp(strat, "simple") == 0)
	{
		ft_set_bench(bch, 1);
		ft_simple_sort(a, b, bch);
	}
	else if (ft_strcmp(strat, "medium") == 0)
	{
		ft_set_bench(bch, 2);
		ft_block_sort(a, b, bch);
	}
	else if (ft_strcmp(strat, "complex") == 0)
	{
		ft_set_bench(bch, 3);
		ft_radix_sort(a, b, bch);
	}
	else
		ft_adaptive_sort(a, b, bch);
}
