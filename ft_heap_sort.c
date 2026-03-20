/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumdogan <sumdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 04:00:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/15 05:56:52 by sumdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<stdio.h>
static void	ft_rotate_up(t_stack **stack, int pos, t_bench *bench, char name)
{
	if(pos <= 0)
		return ;
	while (pos-- > 0)
	{
		if (name == 'a')
			ft_ra(stack, bench);
		else
			ft_rb(stack, bench);
	}
}

void	ft_bring_to_top(t_stack **stack, int pos, t_bench *bench, char name)
{
	int	size;
	int rotations;

	if (!stack || !*stack)
		return ;
	size = ft_stack_size(*stack);
	if (pos <= size / 2)
		ft_rotate_up(stack, pos, bench, name);
	else
	{
		rotations = size - pos;
		while (rotations-- > 0)
		{
			if (name == 'a')
				ft_rra(stack, bench);
			else
				ft_rrb(stack, bench);
		}	
	}
}
void	ft_index_stack(t_stack *stack)
{
	t_stack *i_node;
	t_stack *j_node;
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
void	ft_heap_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int		size;
	int		max_bits;
	int		i;
	int		j;

	if (!a || !*a || ft_is_sorted(*a))
		return ;

	size = ft_stack_size(*a);

	ft_index_stack(*a);

	max_bits = 0;
	i = size - 1;
	while ((i >> max_bits) != 0)
		max_bits++;

	for (i = 0; i < max_bits; i++)
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
	}
}























































// int	ft_stack_size(t_stack *stack)
// {
// 	int	size = 0;

// 	while (stack)
// 	{
// 		size++;
// 		stack = stack->next;
// 	}
// 	return (size);
// }
// void	ft_heap_sort(t_stack **a, t_stack **b, t_bench *bench)
// {
// 	int		size;
// 	int		max_bits;
// 	int		i;
// 	int		j;
// 	//t_stack	*tmp;

// 	if (!a || !*a || ft_is_sorted(*a))
// 		return ;

// 	size = ft_stack_size(*a);

// 	ft_init_stack(*a);

// 	max_bits = 0;
// 	i = size - 1;
// 	while ((i >> max_bits) != 0)
// 		max_bits++;

// 	for (i = 0; i < max_bits; i++)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			if (((*a)->index >> i) & 1)
// 				ft_ra(a, bench);
// 			else
// 				ft_pb(a, b, bench);
// 			j++;
// 		}
// 		while (*b)
// 			ft_pa(a, b, bench);
// 	}
// }
// void	ft_heap_sort(t_stack **a, t_stack **b, t_bench *bench)
// {
// 	int	size;
// 	int	chunk_max;

// 	if (!a || !*a || ft_is_sorted(*a))
// 		return ;

// 	// input büyüklüğüne göre chunk ayarı
// 	size = ft_stack_size(*a);
// 	if (size <= 100)
// 		chunk_max = 20;
// 	else
// 		chunk_max = 50;

// 	while (*a)
// 	{
// 		int	count = 0;
// 		t_stack *tmp = *a;

// 		// chunk mantığı: top chunk_max sayısını b'ye gönder
// 		while (tmp && count < chunk_max)
// 		{
// 			int	min_pos = ft_get_min_pos(*a);
// 			int	sz = ft_stack_size(*a);

// 			// rotate optimizasyonu
// 			if (min_pos <= sz / 2)
// 				while (min_pos-- > 0)
// 					ft_ra(a, bench);
// 			else
// 			{
// 				min_pos = sz - min_pos;
// 				while (min_pos-- > 0)
// 					ft_rra(a, bench);
// 			}

// 			// push b stack
// 			ft_pb(a, b, bench);
// 			count++;
// 			tmp = *a;
// 		}
// 	}

// 	// geri toplama: b stack'teki tüm elemanları a'ya getir
// 	while (*b)
// 		ft_pa(a, b, bench);
// }
// void	ft_heap_sort(t_stack **a, t_stack **b, t_bench *bench)
// {
// 	int	max_pos;
// 	int	size;

// 	if (!a || !*a || ft_is_sorted(*a))
// 		return ;

// 	while (*a)
// 	{
// 		size = ft_stack_size(*a);
// 		max_pos = ft_get_min_pos(*a);

// 		// Güvenlik check (opsiyonel ama daha doğru
// 		if (max_pos < 0 || max_pos >= size)
// 			return ;

// 		// Daha az operasyon için optimize rotate
// 		if (max_pos <= size / 2)
// 		{
// 			while (max_pos-- > 0)
// 				ft_ra(a, bench);
// 		}
// 		else
// 		{
// 			max_pos = size - max_pos;
// 			while (max_pos-- > 0)
// 				ft_rra(a, bench);
// 		}

// 		ft_pb(a, b, bench);
// 	}

// 	// Geri toplama
// 	while (*b)
// 		ft_pa(a, b, bench);
// }


// void	ft_heap_sort(t_stack **a, t_stack **b, t_bench *bench)
// {
// 	int	max_pos;

// 	if (!a || !*a || ft_is_sorted(*a))
// 		return ;
// 	while (*a)
// 	{
// 		max_pos = ft_get_max_pos(*a);
// 		if (max_pos < 0 || max_pos >= ft_stack_size(*a))
// 			return ;
// 		ft_bring_to_top(a, max_pos, bench, 'a');
// 		ft_pb(a, b, bench);
// 	}
// 	while (*b)
// 	{
// 		ft_pa(a, b, bench);
// 	}
// }
