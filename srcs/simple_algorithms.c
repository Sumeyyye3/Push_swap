/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:37:12 by mozay             #+#    #+#             */
/*   Updated: 2026/03/05 22:02:35 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// stack boyutunu hesaplar.
int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack -> next;
	}
	return (size);
}

// // stack sıralanmış bir şekilde gelip gelmediğini kontrol eder
int	ft_is_sorted(t_stack *stack)
{
	t_stack	*temp;
	temp = stack;
	while (temp && temp -> next)
	{
		if (temp -> value < temp -> next -> value)
			return (1);
		temp = temp -> next;
	}
	return (0);
}

// basit durumlar için olan algoritma ==> buble sort kullanıyor.
// en küçük sayıyı bulup en üste getiriyor
void	ft_simple_sort(t_stack **first, t_stack **second)
{
	int	min;
	int	min_pos;
	int	size;

	while (*first)
	{
		size = ft_stack_size(*first);
		min = get_min_value(*first);
		min_pos = get_position(*first, min);
		// sayıların yarısına kadar arama yapma durumu
		if (min_pos <= size / 2)
		{
			while (min_pos-- > 0)
				rotate_a(first);
		}		
		// sondan arama durumu
		else
		{
			while (min_pos++ < size -1)
				reverse_rotate_a(first);
		}
		push_b(first, second);
	}
	while (*second)
		push_a(first, second);
}
