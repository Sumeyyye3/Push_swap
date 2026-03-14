/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumdogan <sumdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 02:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/14 07:03:40 by sumdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	ft_process_args(int ac, char **av, char ***nums, int *cnt)
{
	*cnt = ft_count_numbers(ac, av);
	*nums = ft_extract_numbers(ac, av, cnt);
	if (!*nums)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
}

static void	ft_initialize(t_stack **a, t_bench *bench, int ac, char **av)
{
	char	**nums;  // av ' nin kopyası olacak
	int		cnt;

	ft_process_args(ac, av, &nums, &cnt);
	*a = ft_init_stack(nums);
	if (!*a)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	//ft_assign_indices(*a);
	ft_init_bench(bench);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*strategy;
	t_bench	bench;

	if (ac < 2)
		return (0);
	a = NULL;
	ft_check_arguments(ac , av);
	ft_initialize(&a, &bench, ac, av);  // av kopyası numbs oluşturur
	if (bench.mode)
		bench.disorder = ft_compute_disorder(a);
	strategy = NULL;
	b = NULL;
	ft_sort_stacks(&a, &b, strategy, &bench);
	if (bench.mode)
		ft_print_bench(&bench);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
