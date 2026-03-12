/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 02:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/13 01:02:40 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*ft_create_node(long value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = (int)value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	ft_add_node(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!*stack)
		*stack = new;
	else
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

void	ft_assign_indices(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		idx;

	tmp = stack;
	while (tmp)
	{
		idx = 0;
		tmp2 = stack;
		while (tmp2)
		{
			if (tmp->value > tmp2->value)
				idx++;
			tmp2 = tmp2->next;
		}
		tmp->index = idx;
		tmp = tmp->next;
	}
}

static t_stack	*ft_init_stack_args(char **args, int cnt)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = 0;
	while (i < cnt)
	{
		ft_add_node(&stack, ft_create_node(ft_atol(args[i])));
		i++;
	}
	return (stack);
}

t_stack	*ft_init_stack(int ac, char **av, int *flag)
{
	t_stack	*stack;
	char	**args;
	int		cnt;

	stack = NULL;
	*flag = 0;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args || !args[0])
			return (NULL);
		*flag = 1;
	}
	else
		args = av + 1;
	cnt = 0;
	while (args[cnt])
		cnt++;
	stack = ft_init_stack_args(args, cnt);
	if (*flag == 1)
		ft_free_split(args);
	return (stack);
}
