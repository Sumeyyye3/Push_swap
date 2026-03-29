/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/29 22:31:58 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_position(t_stack *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

int	ft_get_min_pos(t_stack *stack)
{
	int	min;
	int	pos;
	int	min_pos;

	if (!stack)
		exit (1);
	min = stack->value;
	min_pos = 0;
	pos = 0;
	while (stack->next)
	{
		stack = stack->next;
		pos++;
		if (stack->value < min)
		{
			min = stack->value;
			min_pos = pos;
		}
	}
	return (min_pos);
}

int	ft_get_max_pos(t_stack *stack)
{
	int	max;
	int	pos;
	int	max_pos;

	if (!stack)
		return (-1);
	max = stack->value;
	max_pos = 0;
	pos = 0;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (max_pos);
}

int	ft_get_min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	ft_get_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}
