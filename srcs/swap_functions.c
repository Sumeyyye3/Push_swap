/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:59:55 by mozay             #+#    #+#             */
/*   Updated: 2026/03/04 20:31:51 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;

	first = *stack;
	second = first->next;

	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	swap_a(t_stack **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	swap(a);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	swap(b);
	write(1, "sb\n", 3);
}

void	swap_ss(t_stack **a, t_stack **b)
{
	int	swapped_a;
	int	swapped_b;

	swapped_a = 0;
	swapped_b = 0;

	if (a && *a && (*a)->next)
	{
		swap(a);
		swapped_a = 1;
	}
	if (b && *b && (*b)->next)
	{
		swap(b);
		swapped_b = 1;
	}
	
	if (swapped_a || swapped_b)
		write(1, "ss\n", 3);
}