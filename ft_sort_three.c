/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumdogan <sumdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:00:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/14 07:10:23 by sumdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<unistd.h>
static void	ft_case_one(t_stack **a, t_bench *bench)
{
	ft_sa(a, bench);
}

static void	ft_case_two(t_stack **a, t_bench *bench)
{
	write(1,"hello",5);
	ft_sa(a, bench);
	ft_rra(a, bench);
}

static void	ft_case_three(t_stack **a, t_bench *bench)
{
	ft_ra(a, bench);
}

static void	ft_case_four(t_stack **a, t_bench *bench)
{
	ft_sa(a, bench);
	ft_ra(a, bench);
}

void	ft_sort_three(t_stack **a, t_bench *bench)
{
	int	f;
	int	s;
	int	t;

	f = (*a)->value;
	s = (*a)->next->value;
	t = (*a)->next->next->value;
	if (f > s && s < t && f < t)
		ft_case_one(a, bench);
	else if (f > s && s > t)
		ft_case_two(a, bench);
	else if (f > s && s < t && f > t)
		ft_case_three(a, bench);
	else if (f < s && s > t && f < t)
		ft_case_four(a, bench);
	else if (f < s && s > t && f > t)
		ft_rra(a, bench);
}
