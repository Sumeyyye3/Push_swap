
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:00:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/10 00:00:00 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>  
#include<stddef.h>

static t_stack	*ft_init_stack(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*new_node;
	char	**args;
	int		i;
	int		flag;

	stack_a = NULL;
	flag = 0;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		flag = 1;
	}
	else
		args = av + 1;
	i = 0;
	while (args[i])
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->value = (int)ft_atol(args[i]);
		new_node->next = NULL;
		if (!stack_a)
			stack_a = new_node;
		else
		{
			t_stack *last = stack_a;
			while (last->next)
				last = last->next;
			last->next = new_node;
		}
		i++;
	}
	if (flag)
		ft_free(args);
	return (stack_a);
}

static void	ft_free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

static void	ft_sort(t_stack **stack_a)
{
	int		size;
	t_stack	*stack_b;

	stack_b = NULL;
	size = ft_stack_size(*stack_a);
	if (size <= 1 || ft_is_sorted(*stack_a))
		return ;
	if (size == 2)
	{
		if ((*stack_a)->value < (*stack_a)->next->value)
			swap_a(stack_a);
		return ;
	}
	if (size <= 5)
	{
		ft_simple_sort(stack_a, &stack_b);
		return ;
	}
	if (size <= 100)
	{
		*stack_a = ft_block_based_sort(*stack_a);
		return ;
	}
	*stack_a = heap_sort(*stack_a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	if (ac < 2)
		return (0);
	if (!check_arguments(ac, av))
		return (1);
	stack_a = ft_init_stack(ac, av);
	if (!stack_a)
		return (1);
	ft_sort(&stack_a);
	ft_free_stack(&stack_a);
	return (0);
}