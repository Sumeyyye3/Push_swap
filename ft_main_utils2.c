/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 02:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/29 20:57:24 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_loop(int ac, char **av, int cnt)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_is_flag(av[i]))
			cnt++;
		i++;
	}
	return (cnt);
}

static int	ft_is_flag(char *arg)
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

int	ft_count_numbers(int ac, char **av)
{
	char	**args;
	int		cnt;
	int		i;

	cnt = 0;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args)
			exit(1);
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
	return (ft_loop(ac, av, cnt));
}

static char	**ft_extract_multi_args(int ac, char **av, int *cnt)
{
	char	**nums;
	int		i;
	int		j;

	nums = malloc(sizeof(char *) * (*cnt + 1));
	if (!nums)
		exit(1);
	i = 1;
	j = 0;
	while (i < ac)
	{
		if (!ft_is_flag(av[i]))
			nums[j++] = ft_strdup(av[i]);
		i++;
	}
	nums[j] = NULL;
	return (nums);
}

char	**ft_extract_numbers(int ac, char **av, int *cnt)
{
	char	**parts;
	char	**nums;
	int		i;
	int		j;

	if (ac == 2)
	{
		parts = ft_split(av[1], ' ');
		if (!parts)
			exit(1);
		nums = malloc(sizeof(char *) * (*cnt + 1));
		if (!nums)
			exit(1);
		i = 0;
		j = 0;
		while (parts[i])
		{
			if (!ft_is_flag(parts[i]))
				nums[j++] = ft_strdup(parts[i]);
			i++;
		}
		nums[j] = NULL;
		ft_free_split(parts);
		return (nums);
	}
	return (ft_extract_multi_args(ac, av, cnt));
}
