/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/12 23:28:08 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_rra(t_stack **a, t_bench *bench)
{
	t_stack	*prev;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = *a;
	*a = last;
	ft_print_op("rra", bench);
}

void	ft_rrb(t_stack **b, t_bench *bench)
{
	t_stack	*prev;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	prev = NULL;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = *b;
	*b = last;
	ft_print_op("rrb", bench);
}

void	ft_ra(t_stack **a, t_bench *bench)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	ft_print_op("ra", bench);
}

void	ft_rb(t_stack **b, t_bench *bench)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = tmp;
	ft_print_op("rb", bench);
}
