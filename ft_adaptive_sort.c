/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/04/12 00:54:15 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_control(t_stack **a, t_stack **b, t_bench *bch)
{
	if (ft_stack_size(*a) == 2)
		ft_sort_two(a, bch);
	else if (ft_stack_size(*a) == 3)
		ft_tiny_fix(a, bch);
	else if (ft_stack_size(*a) == 4 || ft_stack_size(*a) == 5)
		ft_sort_four_and_five(a, b, bch);
}

void	ft_set_bench(t_bench *bch, int type)
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
		bch->complexity = "O(n*logn)";
	}
	else
	{
		bch->strategy = "Adaptive";
		if (bch->disorder < 0.2)
			bch->complexity = "O(n^2)";
		else if (bch->disorder >= 0.2 && bch->disorder < 0.5)
			bch->complexity = "O(n*sqrt(n))";
		else if (bch->disorder >= 0.5)
			bch->complexity = "O(n*logn)";
	}
}

void	ft_tiny_fix(t_stack **a, t_bench *bench)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	ft_set_bench(bench, 4);
	if (top > mid && top > bot && mid < bot)
		ft_ra(a, bench);
	else if (top > mid && top > bot && mid > bot)
	{
		ft_sa(a, bench);
		ft_rra(a, bench);
	}
	else if (top < mid && top < bot && mid > bot)
	{
		ft_rra(a, bench);
		ft_sa(a, bench);
	}
	else if (top > mid && top < bot)
		ft_sa(a, bench);
	else if (top < mid && top > bot)
		ft_rra(a, bench);
}

void	ft_adaptive_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	double	disorder;
	int		size;

	disorder = ft_compute_disorder(*a);
	size = ft_stack_size(*a);
	ft_set_bench(bench, 4);
	if (size == 3)
		ft_tiny_fix(a, bench);
	else if (disorder < 0.2)
		ft_simple_sort(a, b, bench);
	else if (disorder >= 0.2 && disorder < 0.5)
		ft_block_sort(a, b, bench);
	else if (disorder >= 0.5)
		ft_radix_sort(a, b, bench);
}

void	ft_sort_stacks(t_stack **a, t_stack **b, char *strat, t_bench *bch)
{
	if (!a || !*a || ft_is_sorted(*a))
		return ;
	if (ft_stack_size(*a) <= 5 && ft_strcmp(strat, "simple") != 0)
		ft_control(a, b, bch);
	else if (ft_strcmp(strat, "simple") == 0)
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
