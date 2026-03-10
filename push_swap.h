/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:56:17 by mozay             #+#    #+#             */
/*   Updated: 2026/03/07 13:52:00 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;
#include<stdlib.h>
t_stack *heap_sort(t_stack *stack_a);

void		push_a(t_stack **a, t_stack **b);
void		push_b(t_stack **a, t_stack **b);

void	    swap_a(t_stack **a);
void	    swap_b(t_stack **b);
void	    swap_ss(t_stack **a, t_stack **b);

void		rotate_a(t_stack **a);
void	    rotate_b(t_stack **b);
void    	rotate_rr(t_stack **a, t_stack **b);

void		reverse_rotate_a(t_stack **a);
void		reverse_rotate_b(t_stack **b);
void		reverse_rotate_rrr(t_stack **a, t_stack **b);

int		ft_isnumber(char *numbers);
int		ft_includes(long argument, char **new_av, int i);
int		ft_controls(char **new_av, int flag);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
long	ft_atol(const char *nptr);

int		check_arguments(int ac, char **av);
int		get_min_value(t_stack *stack);
int		get_max_value(t_stack *stack);
int		get_position(t_stack *stack, int value);
int		ft_is_sorted(t_stack *stack);
int		ft_stack_size(t_stack *stack);

void	ft_free(char **new_av);
void    ft_top_stack(t_stack **stack_a, int max_index);
void	ft_simple_sort(t_stack **first, t_stack **second);
t_stack    *ft_block_based_sort(t_stack *stack_a);
t_stack	*ft_lstlast(t_stack *stack);

#endif