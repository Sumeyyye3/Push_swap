/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 02:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/29 22:17:34 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_token(char *str, int *strategy_count)
{
	if (ft_is_strategy_flag(str))
	{
		(*strategy_count)++;
		return ;
	}
	if (ft_is_known_flag(str))
		return ;
	if ((str[0] == '-' && str[1] == '-') || !ft_isnumber(str))
		ft_error_and_exit();
}

static void	ft_validate_tokens(char **tokens)
{
	int	i;
	int	strategy_count;

	i = 0;
	strategy_count = 0;
	while (tokens[i])
	{
		ft_check_token(tokens[i], &strategy_count);
		i++;
	}
	if (strategy_count > 1)
		ft_error_and_exit();
}

static void	ft_validate_numbers(int ac, char **av)
{
	char	**nums;
	int		cnt;
	int		i;
	long	val;

	cnt = ft_count_numbers(ac, av);
	if (cnt <= 0)
		ft_error_and_exit();
	nums = ft_extract_numbers(ac, av, &cnt);
	if (!nums || ft_check_duplicate(nums))
		ft_error_and_exit();
	i = 0;
	while (nums[i])
	{
		val = ft_atol(nums[i]);
		if (val < INT_MIN || val > INT_MAX)
		{
			ft_free_split(nums);
			ft_error_and_exit();
		}
		i++;
	}
	ft_free_split(nums);
}

void	ft_check_arguments(int ac, char **av, char *strategy)
{
	char	**tokens;

	(void)strategy;
	if (!av || !*av)
		exit(1);
	if (ac == 2)
	{
		tokens = ft_split(av[1], ' ');
		if (!tokens)
			exit(1);
		ft_validate_tokens(tokens);
		ft_free_split(tokens);
	}
	else
		ft_validate_tokens(av + 1);
	ft_validate_numbers(ac, av);
}
