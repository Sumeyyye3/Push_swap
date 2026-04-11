/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:00:00 by mozay             #+#    #+#             */
/*   Updated: 2026/04/12 00:41:08 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	ft_free_all(t_stack **a, t_stack **b)
{
	ft_free_stack(a);
	ft_free_stack(b);
}

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_sort_two(t_stack **a, t_bench *bench)
{
	ft_set_bench(bench, 4);
	if ((*a)->value > (*a)->next->value)
		ft_sa(a, bench);
}

void	ft_simple_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	min_pos;
	int	size;

	size = ft_stack_size(*a);
	if (size == 2)
		ft_sort_two(a, bench);
	else if (size == 3)
		ft_tiny_fix(a, bench);
	else if (size == 4 || size == 5)
		ft_sort_four_and_five(a, b, bench);
	else
	{
		while (*a)
		{
			min_pos = ft_get_min_pos(*a);
			while (min_pos-- > 0)
				ft_ra(a, bench);
			ft_pb(a, b, bench);
		}
		while (*b)
			ft_pa(a, b, bench);
	}
}
