/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumdogan <sumdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 02:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/15 06:09:44 by sumdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_process_args(int ac, char **av, char ***nums, int *cnt)
{
	long	arr_nums;
	int		i;

	*cnt = ft_count_numbers(ac, av); // 2
	*nums = ft_extract_numbers(ac, av, cnt);
	if (!*nums)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	i = 0;
	while ((*nums)[i])
	{
		arr_nums = ft_atol((*nums)[i]);
		if (arr_nums < INT_MIN || arr_nums > INT_MAX)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
}

static void	ft_initialize(t_stack **a, t_bench *bench, int ac, char **av)
{
	char **nums;
	int cnt;
	ft_process_args(ac, av, &nums, &cnt);
	*a = ft_init_stack(nums);
	ft_free_split(nums);
	if (!*a)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	ft_assign_indices(*a);
	ft_init_bench(bench);
}

static char	*ft_find_strategy(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_strcmp(av[i], "--simple") == 0)
			return ("simple");
		else if (ft_strcmp(av[i], "--medium") == 0)
			return ("medium");
		else if (ft_strcmp(av[i], "--complex") == 0)
			return ("complex");
		i++;
	}
	return ("none");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*strategy;
	t_bench	bench;

	if (ac < 2)
		return (0);
	strategy = ft_find_strategy(av);
	ft_check_arguments(ac, av, strategy);
	ft_memset(&bench, 0, sizeof(t_bench));
	ft_initialize(&a, &bench, ac, av);
	if (bench.mode)
		bench.disorder = ft_compute_disorder(a);
	b = NULL;
	ft_sort_stacks(&a, &b, strategy, &bench);
	if (bench.mode)
		ft_print_bench(&bench);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
