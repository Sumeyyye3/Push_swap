/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:59:34 by mozay             #+#    #+#             */
/*   Updated: 2026/03/04 20:28:09 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **new_av)
{
    int	j;

	j = 0;    
    if (!new_av)
        return ;
    while (new_av[j])
    {
        free(new_av[j]);
        j++;
    }
    free(new_av);
}

int	ft_isnumber(char *numbers)
{
	int i;

	i = 0;
	if (!numbers || !numbers[0])
        return (0);
	if (numbers[i] == '+' || numbers[i] == '-')
		i++;
	if (!numbers[i])
		return (0);
	while (numbers[i] >= '0' && numbers[i] <= '9')
	{
		i++;
	}
    if (numbers[i] != '\0')
        return (0);
	return (1);
}

int	ft_includes(long argument, char **new_av, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (ft_atol(new_av[j]) == argument)
			return (0);
		j++;
	}
	return (1);
}

int	ft_controls(char **new_av, int flag)
{
    int i;
    long argument;

    i = 0;
    while (new_av[i])
    {
        argument = ft_atol(new_av[i]);
        if (!ft_isnumber(new_av[i]) || 
            argument < -2147483648 || 
            argument > 2147483647)
        {
            write(2, "Error\n", 6);
            if (flag == 1)
                ft_free(new_av);
            return (0);
        }
        if (!ft_includes(argument, new_av, i))
        {
            write(2, "Error\n", 6);
            if (flag == 1)
                ft_free(new_av);
            return (0);
        }
        i++;
    }
    return (1);
}

int	check_arguments(int ac, char **av)
{
    int flag;
    char **new_av;

    flag = 0;
    if (ac == 2)
    {
        new_av = ft_split(av[1], ' ');
        if (!new_av || !new_av[0])
        {
            write(2, "Error\n", 6);
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
