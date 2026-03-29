/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 04:00:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/29 23:49:35 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_stack(t_stack *stack)
{
	t_stack	*i_node;
	t_stack	*j_node;
	int		index;

	i_node = stack;
	while (i_node)
	{
		index = 0;
		j_node = stack;
		while (j_node)
		{
			if (j_node->value < i_node->value)
				index++;
			j_node = j_node->next;
		}
		i_node->index = index;
		i_node = i_node->next;
	}
}

static void	ft_radix_cnt(int max_bits, t_stack **a, t_stack **b, t_bench *bench)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = ft_stack_size(*a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				ft_ra(a, bench);
			else
				ft_pb(a, b, bench);
			j++;
		}
		while (*b)
			ft_pa(a, b, bench);
		i++;
	}
}

void	ft_radix_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int		size;
	int		max_bits;
	int		max_index;

	if (!a || !*a || ft_is_sorted(*a))
		return ;
	size = ft_stack_size(*a);
	ft_index_stack(*a);
	max_index = size - 1;
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	ft_radix_cnt(max_bits, a, b, bench);
}
