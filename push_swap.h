/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:56:17 by mozay             #+#    #+#             */
/*   Updated: 2026/03/04 20:37:02 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "42-Libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

int		push_a(t_stack **a, t_stack **b);
int		push_b(t_stack **a, t_stack **b);

void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_ss(t_stack **a, t_stack **b);

int		rotate_a(t_stack **a);
int		rotate_b(t_stack **b);
int		rotate_rr(t_stack **a, t_stack **b);

int		reverse_rotate_a(t_stack **a);
int		reverse_rotate_b(t_stack **b);
int		reverse_rotate_rrr(t_stack **a, t_stack **b);

int		ft_isnumber(char *numbers);
int		ft_includes(long argument, char **new_av, int i);
int		ft_controls(char **new_av, int flag);
int		check_arguments(int ac, char **av);

void	ft_free(char **new_av);
int		get_min_value(t_stack *stack);
int		get_max_value(t_stack *stack);
int		get_position(t_stack *stack, int value);

#endif