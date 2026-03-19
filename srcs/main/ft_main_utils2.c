/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumdogan <sumdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 02:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/15 00:30:46 by sumdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_count_numbers(int ac, char **av)
{
	char	**args;
	int		cnt;


	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args)
			exit (1);
		cnt = 0;
		while (args[cnt])
			cnt++;
		ft_free_split(args);
		return (cnt);
	}
	return (ac - 1);
}

static char	**ft_extract_multi_args(int ac, char **av, int *cnt)
{                                  // 3     ./a.out 2 1      2
	char	**nums;
	int		i;
	int		j;

	nums = malloc(sizeof(char *) * (*cnt + 1));
	if (!nums)
		exit (1);
	i = 1;
	j = 0;
	while (i < ac)
	{
		nums[j++] = ft_strdup(av[i]);
		i++;
	}
	nums[j] = NULL;
	return (nums);
}

static char	**ft_extract_single_arg(char *arg)
{
	char	**nums;

	nums = ft_split(arg, ' ');
	if (!nums)
		exit (1);
	return (nums);
}

char	**ft_extract_numbers(int ac, char **av, int *cnt)
{                       
	if (ac == 2)
		return (ft_extract_single_arg(av[1]));
	else
		return (ft_extract_multi_args(ac, av, cnt));
}
