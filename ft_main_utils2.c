/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 02:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/04/12 00:52:54 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_numbers(int ac, char **av)
{
	if (ac == 2)
		return (ft_count_single_arg(av[1]));
	return (ft_loop(ac, av, 0));
}

static char	**ft_extract_single_arg(char *arg, int *cnt)
{
	char	**parts;
	char	**nums;
	int		i;
	int		j;

	parts = ft_split(arg, ' ');
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

static void	ft_extract_parts(char **parts, char **nums, int *j)
{
	int	k;

	k = 0;
	while (parts[k])
	{
		if (!ft_is_flag(parts[k]))
			nums[(*j)++] = ft_strdup(parts[k]);
		k++;
	}
}

static char	**ft_extract_multi_args(int ac, char **av, int *cnt)
{
	char	**nums;
	char	**parts;
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
		{
			parts = ft_split(av[i], ' ');
			if (!parts)
				exit(1);
			ft_extract_parts(parts, nums, &j);
			ft_free_split(parts);
		}
		i++;
	}
	nums[j] = NULL;
	return (nums);
}

char	**ft_extract_numbers(int ac, char **av, int *cnt)
{
	if (ac == 2)
		return (ft_extract_single_arg(av[1], cnt));
	return (ft_extract_multi_args(ac, av, cnt));
}
