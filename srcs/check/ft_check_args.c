/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumdogan <sumdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 02:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/14 08:14:21 by sumdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <unistd.h>
#include <stddef.h>
int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (0); // rakam değilse false
		i++;
	}
	return (1);
}

#include <stddef.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char)(s1[i]) != (unsigned char)(s2[i]))
		{
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		}
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_check_duplicate(char **nums, char *num,int *flag)
{
	int i;

	i = 0;
	while(nums[i])
	{
		if(!ft_strcmp(nums[i],num))
			(*flag)++;
		i++;
	}
}

void	ft_check_arguments(int ac , char **av)
{
	int	i;
	int	flag;
	char **nums;

	if (!av || !*av)
		exit(1);
	nums = av;
	if(ac == 2)
	{
		nums = ft_split(av[1],' ');
	}
	i = 1;
	while (nums[i])
	{
		if (!ft_isnumber(nums[i]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		flag = 0;
		ft_check_duplicate(nums,nums[i],&flag);
		if(flag > 1)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);	
		}	
		i++;
	}
}
