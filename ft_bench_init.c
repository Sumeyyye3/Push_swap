/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 02:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/19 15:15:00 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_stack_to_array(t_stack *stack, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (stack)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
	return (arr);
}

static int	ft_count_mistakes(int *arr, int size)
{
	int	i;
	int	j;
	int	mistakes;

	mistakes = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes);
}

double	ft_compute_disorder(t_stack *stack)
{
	int		*arr;
	int		size;
	int		mistakes;
	double	total_pairs;

	size = ft_stack_size(stack);
	if (size <= 1)
		return (0.0);
	arr = ft_stack_to_array(stack, size);
	if (!arr)
		return (0.0);
	mistakes = ft_count_mistakes(arr, size);
	free(arr);
	total_pairs = (size * (size - 1)) / 2.0;
	return (mistakes / total_pairs);
}

void	ft_init_bench(t_bench *bench)
{
	bench->disorder = 0.0;
	bench->strategy = NULL;
	bench->complexity = NULL;
	bench->total_ops = 0;
	bench->ops_sa = 0;
	bench->ops_sb = 0;
	bench->ops_ss = 0;
	bench->ops_pa = 0;
	bench->ops_pb = 0;
	bench->ops_ra = 0;
	bench->ops_rb = 0;
	bench->ops_rr = 0;
	bench->ops_rra = 0;
	bench->ops_rrb = 0;
	bench->ops_rrr = 0;
}
