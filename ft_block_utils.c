/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_block_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/04/12 00:53:07 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_loop(int ac, char **av, int cnt)
{
	char	**parts;
	int		i;
	int		k;

	i = 1;
	while (i < ac)
	{
		if (!ft_is_flag(av[i]))
		{
			parts = ft_split(av[i], ' ');
			if (!parts)
				exit(1);
			k = 0;
			while (parts[k])
			{
				if (!ft_is_flag(parts[k]))
					cnt++;
				k++;
			}
			ft_free_split(parts);
		}
		i++;
	}
	return (cnt);
}

int	ft_count_single_arg(char *arg)
{
	char	**args;
	int		cnt;
	int		i;

	args = ft_split(arg, ' ');
	if (!args)
		exit(1);
	if (args[0] && ft_is_flag(args[0]))
	{
		ft_free_split(args);
		return (0);
	}
	cnt = 0;
	i = 0;
	while (args[i])
	{
		if (!ft_is_flag(args[i]))
			cnt++;
		i++;
	}
	ft_free_split(args);
	return (cnt);
}

static void	ft_rotate_to_pos(t_stack **a, int pos, t_bench *bench)
{
	int	size;

	size = ft_stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ft_ra(a, bench);
	}
	else
	{
		while (pos++ < size)
			ft_rra(a, bench);
	}
}

void	ft_push_chunk(t_stack **a, t_stack **b, int range[2], t_bench *bench)
{
	int	pos;

	while (1)
	{
		pos = ft_find_in_chunk(*a, range[0], range[1]);
		if (pos == -1)
			break ;
		ft_rotate_to_pos(a, pos, bench);
		ft_pb(a, b, bench);
	}
}

void	ft_optimize_b(t_stack **b, t_bench *bench)
{
	int	max_pos;
	int	size;

	if (!b || !*b || !(*b)->next)
		return ;
	size = ft_stack_size(*b);
	max_pos = ft_get_max_pos(*b);
	if (max_pos <= size / 2)
	{
		while (max_pos-- > 0)
			ft_rb(b, bench);
	}
	else
	{
		while (max_pos++ < size)
			ft_rrb(b, bench);
	}
}
