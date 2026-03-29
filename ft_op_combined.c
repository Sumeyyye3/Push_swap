/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_combined.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/29 21:04:11 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_count_op_part(char *op, t_bench *bench)
{
	if (ft_strcmp(op, "sa") == 0)
		bench->ops_sa++;
	else if (ft_strcmp(op, "sb") == 0)
		bench->ops_sb++;
	else if (ft_strcmp(op, "ss") == 0)
		bench->ops_ss++;
	else if (ft_strcmp(op, "pa") == 0)
		bench->ops_pa++;
	else if (ft_strcmp(op, "pb") == 0)
		bench->ops_pb++;
	else if (ft_strcmp(op, "ra") == 0)
		bench->ops_ra++;
	else if (ft_strcmp(op, "rb") == 0)
		bench->ops_rb++;
	else if (ft_strcmp(op, "rr") == 0)
		bench->ops_rr++;
	else if (ft_strcmp(op, "rra") == 0)
		bench->ops_rra++;
	else if (ft_strcmp(op, "rrb") == 0)
		bench->ops_rrb++;
	else if (ft_strcmp(op, "rrr") == 0)
		bench->ops_rrr++;
}

void	ft_print_op(char *op, t_bench *bench)
{
	int	i;

	i = 0;
	while (op[i])
	{
		write(1, &op[i], 1);
		i++;
	}
	write(1, "\n", 1);
	if (!bench)
		return ;
	bench->total_ops++;
	ft_count_op_part(op, bench);
}
