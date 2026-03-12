/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 02:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/13 00:27:24 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	ft_check_number(char *str, long arg, char **av, int flag)
{
	if (!ft_isnumber(str))
	{
		ft_putstr_fd("Error\n", 2);
		if (flag == 1)
			ft_free(av);
		return (0);
	}
	if (arg < -2147483648 || arg > 2147483647)
	{
		ft_putstr_fd("Error\n", 2);
		if (flag == 1)
			ft_free(av);
		return (0);
	}
	return (1);
}

static int	ft_check_duplicate(long arg, char **av, int index, int flag)
{
	if (!ft_includes(arg, av, index))
	{
		ft_putstr_fd("Error\n", 2);
		if (flag == 1)
			ft_free(av);
		return (0);
	}
	return (1);
}

static int	ft_process_single_arg(char **av, int i, int flag)
{
	long	arg;

	arg = ft_atol(av[i]);
	if (!ft_check_number(av[i], arg, av, flag))
		return (0);
	if (!ft_check_duplicate(arg, av, i, flag))
		return (0);
	return (1);
}

int	ft_controls(char **new_av, int flag)
{
	int	i;

	i = 0;
	while (new_av[i])
	{
		if (!ft_process_single_arg(new_av, i, flag))
			return (0);
		i++;
	}
	return (1);
}
