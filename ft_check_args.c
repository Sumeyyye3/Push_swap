/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumdogan <sumdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 02:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/15 06:13:25 by sumdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9'))
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

void	ft_check_continue(int i ,int ac,char **nums,char *strategy)
{
	while (nums[i])
	{
		if (ft_strcmp(nums[i], strategy) == 0)
    	{
        	i++;
        	continue;
    	}
		if (!ft_isnumber(nums[i]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		if (ft_check_duplicate(nums))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	if (ac == 2)
        ft_free_split(nums);
}

void	ft_check_arguments(int ac, char **av, char *strategy)
{
	int		i;
	char	**nums;

	if (!av || !*av)
		exit(1);
	nums = av;
	if (ac == 2)
	{
		nums = ft_split(av[1], ' ');
		i = 0;
	}
	else
	{
		nums = av + 1;
		i = 1;
	}
	ft_check_continue(i,ac,nums,strategy);
}
