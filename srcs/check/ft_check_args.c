/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 02:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/13 00:27:05 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	ft_includes(long num, char **av, int index)
{
	int	j;

	j = 0;
	while (j < index)
	{
		if (ft_atol(av[j]) == num)
			return (0);
		j++;
	}
	return (1);
}

int	ft_check_arguments(int ac, char **av)
{
	int		flag;
	char	**new_av;

	flag = 0;
	if (ac == 2)
	{
		new_av = ft_split(av[1], ' ');
		if (!new_av || !new_av[0])
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		flag = 1;
	}
	else if (ac > 2)
		new_av = av + 1;
	else
		return (0);
	if (!ft_controls(new_av, flag))
		return (0);
	if (flag == 1)
		ft_free(new_av);
	return (1);
}
