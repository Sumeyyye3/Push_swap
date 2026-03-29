/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 02:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/29 22:52:14 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_and_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_is_strategy_flag(char *str)
{
	if (ft_strcmp(str, "--simple") == 0)
		return (1);
	if (ft_strcmp(str, "--medium") == 0)
		return (1);
	if (ft_strcmp(str, "--complex") == 0)
		return (1);
	if (ft_strcmp(str, "--adaptive") == 0)
		return (1);
	return (0);
}

int	ft_is_known_flag(char *str)
{
	if (ft_strcmp(str, "--bench") == 0 || ft_is_strategy_flag(str))
		return (1);
	return (0);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_duplicate(char **nums)
{
	int		i;
	int		j;
	long	n1;
	long	n2;

	i = 0;
	while (nums[i])
	{
		n1 = ft_atol(nums[i]);
		j = i + 1;
		while (nums[j])
		{
			n2 = ft_atol(nums[j]);
			if (n1 == n2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
