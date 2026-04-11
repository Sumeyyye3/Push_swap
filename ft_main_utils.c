/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 02:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/04/12 00:10:33 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_min_top(t_stack **a, t_bench *bench)
{
	int	min_pos;
	int	size;
	int	moves;

	size = ft_stack_size(*a);
	min_pos = ft_get_min_pos(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ft_ra(a, bench);
	}
	else
	{
		moves = size - min_pos;
		while (moves-- > 0)
			ft_rra(a, bench);
	}
}

int	ft_is_flag(char *arg)
{
	if (ft_strcmp(arg, "--bench") == 0)
		return (1);
	if (ft_strcmp(arg, "--simple") == 0)
		return (1);
	if (ft_strcmp(arg, "--medium") == 0)
		return (1);
	if (ft_strcmp(arg, "--complex") == 0)
		return (1);
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (1);
	return (0);
}

void	ft_assign_indices(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		idx;

	tmp = stack;
	while (tmp)
	{
		idx = 0;
		tmp2 = stack;
		while (tmp2)
		{
			if (tmp->value > tmp2->value)
				idx++;
			tmp2 = tmp2->next;
		}
		tmp->index = idx;
		tmp = tmp->next;
	}
}

static t_stack	*ft_init_stack_args(char **args, int cnt)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = 0;
	while (i < cnt)
	{
		ft_add_node(&stack, ft_create_node(ft_atol(args[i])));
		i++;
	}
	return (stack);
}

t_stack	*ft_init_stack(char **nums)
{
	t_stack	*stack;
	char	**args;
	int		cnt;

	stack = NULL;
	args = nums;
	cnt = 0;
	while (args[cnt])
		cnt++;
	stack = ft_init_stack_args(args, cnt);
	return (stack);
}
