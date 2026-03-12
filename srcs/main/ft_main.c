/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 02:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/13 01:06:10 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	ft_process_args(int ac, char **av, char ***nums, int *cnt)
{
	*cnt = ft_count_numbers(ac, av);
	if (*cnt == 0)
		return (0);
	*nums = ft_extract_numbers(ac, av, cnt);
	if (!*nums)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (!ft_check_arguments(*cnt + 1, *nums))
	{
		if (ac == 2)
			ft_free_split(*nums);
		else
			free(*nums);
		return (-1);
	}
	return (1);
}

static t_stack	*ft_create_stack(int ac, char **nums, int cnt, int *flag)
{
	t_stack	*a;

	a = ft_init_stack(cnt + 1, nums, flag);
	if (ac == 2)
		ft_free_split(nums);
	else
		free(nums);
	return (a);
}

static int	ft_initialize(t_stack **a, t_bench *bench, int ac, char **av)
{
	char	**nums;
	int		cnt;
	int		flag;
	int		res;

	res = ft_process_args(ac, av, &nums, &cnt);
	if (res == -1)
		return (-1);
	if (res == 0)
		return (0);
	*a = ft_create_stack(ac, nums, cnt, &flag);
	if (!*a)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	ft_assign_indices(*a);
	ft_init_bench(bench);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*strategy;
	t_bench	bench;
	int		res;

	if (ac < 2)
		return (0);
	res = ft_initialize(&a, &bench, ac, av);
	if (res == -1)
		return (1);
	if (res == 0)
		return (0);
	b = NULL;
	if (bench.mode)
		bench.disorder = ft_compute_disorder(a);
	ft_sort_stacks(&a, &b, strategy, &bench);
	if (bench.mode)
		ft_print_bench(&bench);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
