/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:59:34 by mozay             #+#    #+#             */
/*   Updated: 2026/03/30 00:15:35 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_bench
{
	double	disorder;
	char	*strategy;
	char	*complexity;
	int		total_ops;
	int		mode;
	int		ops_sa;
	int		ops_sb;
	int		ops_ss;
	int		ops_pa;
	int		ops_pb;
	int		ops_ra;
	int		ops_rb;
	int		ops_rr;
	int		ops_rra;
	int		ops_rrb;
	int		ops_rrr;
}	t_bench;

t_stack	*ft_create_node(long value);
t_stack	*ft_init_stack(char **nums);

void	ft_push_chunk(t_stack **a, t_stack **b, int min, int max, t_bench *bench);
void	ft_sort_stacks(t_stack **a, t_stack **b, char *strat, t_bench *bch);
void	ft_adaptive_sort(t_stack **a, t_stack **b, t_bench *bench);
void	ft_simple_sort(t_stack **a, t_stack **b, t_bench *bench);
void	ft_block_sort(t_stack **a, t_stack **b, t_bench *bench);
void	ft_radix_sort(t_stack **a, t_stack **b, t_bench *bench);
void	ft_check_arguments(int ac, char **av, char *strategy);
void	ft_pa(t_stack **a, t_stack **b, t_bench *bench);
void	ft_pb(t_stack **a, t_stack **b, t_bench *bench);
void	ft_add_node(t_stack **stack, t_stack *new);
void	ft_optimize_b(t_stack **b, t_bench *bench);
void	ft_sort_two(t_stack **a, t_bench *bench);
void	ft_print_op(char *op, t_bench *bench);
void	ft_rra(t_stack **a, t_bench *bench);
void	ft_rrb(t_stack **b, t_bench *bench);
void	ft_ra(t_stack **a, t_bench *bench);
void	ft_rb(t_stack **b, t_bench *bench);
void	ft_sa(t_stack **a, t_bench *bench);
void	ft_sb(t_stack **b, t_bench *bench);
void	ft_assign_indices(t_stack *stack);
void	ft_free_stack(t_stack **stack);
void	ft_index_stack(t_stack *stack);
void	ft_print_bench(t_bench *bench);
void	ft_init_bench(t_bench *bench);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_free_split(char **split);
void	ft_error_and_exit(void);

char	**ft_extract_numbers(int ac, char **av, int *cnt);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);

double	ft_compute_disorder(t_stack *stack);
long	ft_atol(char *str);

int		ft_find_in_chunk(t_stack *stack, int min, int max);
int		ft_get_position(t_stack *stack, int value);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_count_numbers(int ac, char **av);
int		ft_check_duplicate(char **nums);
int		ft_is_strategy_flag(char *str);
int		ft_get_min_pos(t_stack *stack);
int		ft_get_max_pos(t_stack *stack);
int		ft_stack_size(t_stack *stack);
int		ft_is_sorted(t_stack *stack);
int		ft_is_known_flag(char *str);
int		ft_get_min(t_stack *stack);
int		ft_get_max(t_stack *stack);
int		main(int ac, char **av);
int		ft_isnumber(char *str);
int		ft_is_flag(char *arg);

#endif