/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 02:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/04/02 01:27:14 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_process_args(int ac, char **av, char ***nums, int *cnt)
{
	long	arr_num;
	int		i;

	*cnt = ft_count_numbers(ac, av);
	*nums = ft_extract_numbers(ac, av, cnt);
	if (!*nums || *cnt <= 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	i = 0;
	while ((*nums)[i])
	{
		arr_num = ft_atol((*nums)[i]);
		if (arr_num < INT_MIN || arr_num > INT_MAX)
		{
			ft_free_split(*nums);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
}

static void	ft_initialize(t_stack **a, int ac, char **av)
{
	char	**nums;
	int		cnt;

	cnt = 0;
	ft_process_args(ac, av, &nums, &cnt);
	*a = ft_init_stack(nums);
	ft_free_split(nums);
	if (!*a)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	ft_assign_indices(*a);
}

static char	*ft_find_strategy(int ac, char **av)
{
	int		i;
	char	*found;

	i = 1;
	found = NULL;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "--simple") == 0)
			found = "simple";
		else if (ft_strcmp(av[i], "--medium") == 0)
			found = "medium";
		else if (ft_strcmp(av[i], "--complex") == 0)
			found = "complex";
		else if (ft_strcmp(av[i], "--adaptive") == 0)
			found = "adaptive";
		i++;
	}
	if (found)
		return (found);
	return ("adaptive");
}

static int	ft_has_bench_flag(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "--bench") == 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*strategy;
	t_bench	bench;

	if (ac < 2)
		return (0);
	strategy = ft_find_strategy(ac, av);
	ft_check_arguments(ac, av, strategy);
	ft_init_bench(&bench);
	bench.mode = ft_has_bench_flag(ac, av);
	ft_initialize(&a, ac, av);
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
