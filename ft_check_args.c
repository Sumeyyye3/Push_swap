/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumdogan <sumdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 02:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/04/12 10:18:31 by sumdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_validate_tokens(char **tokens)
{
	int	i;
	int	strategy_count;
	int	seen_number;

	i = 0;
	strategy_count = 0;
	seen_number = 0;
	if (tokens[0] && ft_is_known_flag(tokens[0]))
	{
		if (tokens[1] != NULL)
			ft_error_and_exit();
		strategy_count += ft_is_strategy_flag(tokens[0]);
		return ;
	}
	while (tokens[i])
	{
		ft_check_token(tokens[i], &strategy_count, &seen_number);
		i++;
	}
	if (strategy_count > 1)
		ft_error_and_exit();
}

static void	ft_validate_range(char **nums)
{
	int		i;
	long	val;

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
}

static void	ft_validate_numbers(int ac, char **av)
{
	char	**nums;
	int		cnt;

	cnt = ft_count_numbers(ac, av);
	if (cnt <= 0)
		ft_error_and_exit();
	nums = ft_extract_numbers(ac, av, &cnt);
	if (!nums || ft_check_duplicate(nums))
		return ;
	ft_validate_range(nums);
	ft_free_split(nums);
}

static void	ft_validate_multi_args(int ac, char **av)
{
	char	**parts;
	int		i;
	int		strategy_count;

	i = 1;
	strategy_count = 0;
	while (i < ac)
	{
		parts = ft_split(av[i], ' ');
		if (!parts)
			exit(1);
		if (parts[0] && ft_is_strategy_flag(parts[0]) && !parts[1])
			strategy_count++;
		if (strategy_count > 1)
		{
			ft_free_split(parts);
			ft_error_and_exit();
		}
		ft_validate_tokens(parts);
		ft_free_split(parts);
		i++;
	}
}

void	ft_check_arguments(int ac, char **av)
{
	char	**tokens;

	if (!av || !*av)
		exit(1);
	if (ac == 2)
	{
		tokens = ft_split(av[1], ' ');
		if (!tokens)
			exit(1);
		if (tokens[0] && ft_is_flag(tokens[0]))
		{
			ft_free_split(tokens);
			return ;
		}
		ft_validate_tokens(tokens);
		ft_free_split(tokens);
	}
	else
		ft_validate_multi_args(ac, av);
	ft_validate_numbers(ac, av);
}
