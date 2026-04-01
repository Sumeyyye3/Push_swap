/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 02:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/04/02 01:14:04 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_disorder(t_bench *bench)
{
	int	scaled;
	int	int_part;
	int	frac_part;

	ft_putstr_fd("[bench] disorder: ", 2);
	scaled = (int)(bench->disorder * 10000.0 + 0.5);
	int_part = scaled / 100;
	frac_part = scaled % 100;
	ft_putnbr_fd(int_part, 2);
	ft_putchar_fd('.', 2);
	if (frac_part < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(frac_part, 2);
	ft_putstr_fd("%\n", 2);
}

static void	ft_print_total_ops(t_bench *bench)
{
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(bench->total_ops, 2);
	ft_putstr_fd("\n", 2);
}

static void	ft_print_ops_first(t_bench *bench)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(bench->ops_sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(bench->ops_sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(bench->ops_ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(bench->ops_pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(bench->ops_pb, 2);
	ft_putstr_fd("\n", 2);
}

static void	ft_print_ops_second(t_bench *bench)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(bench->ops_ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(bench->ops_rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(bench->ops_rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(bench->ops_rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(bench->ops_rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(bench->ops_rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_print_bench(t_bench *bench)
{
	if (!bench)
		return ;
	ft_print_disorder(bench);
	ft_putstr_fd("[bench] strategy: ", 2);
	if (bench->strategy)
		ft_putstr_fd(bench->strategy, 2);
	else
		ft_putstr_fd("None", 2);
	ft_putstr_fd(" / ", 2);
	if (bench->complexity)
		ft_putstr_fd(bench->complexity, 2);
	else
		ft_putstr_fd("O(1)", 2);
	ft_putstr_fd("\n", 2);
	ft_print_total_ops(bench);
	ft_print_ops_first(bench);
	ft_print_ops_second(bench);
}
