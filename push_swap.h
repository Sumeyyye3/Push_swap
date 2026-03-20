/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:59:34 by mozay             #+#    #+#             */
/*   Updated: 2026/03/13 01:38:51 by mozay            ###   ########.fr       */
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

/* main */
int		main(int ac, char **av);
t_stack	*ft_create_node(long value);
void	ft_add_node(t_stack **stack, t_stack *new);
//void	ft_assign_indices(t_stack *stack);
int	ft_check_duplicate(char **nums);
t_stack	*ft_init_stack(char **nums);
int		ft_count_numbers(int ac, char **av);
char	**ft_extract_numbers(int ac, char **av, int *cnt);

/* check */
void		ft_check_arguments(int ac,char **av, char *strategy);
//int		ft_controls(char **av, int flag);
int		ft_isnumber(char *str);
int		ft_includes(long num, char **av, int index);

/* stack */
//t_stack	*ft_lstnew(int value);
//t_stack	*ft_lstlast(t_stack *lst);
//int		ft_lstsize(t_stack *lst);
int		ft_stack_size(t_stack *stack);
int		ft_is_sorted(t_stack *stack);
int		ft_get_min(t_stack *stack);
int		ft_get_max(t_stack *stack);
int		ft_get_position(t_stack *stack, int value);
int		ft_get_min_pos(t_stack *stack);
int		ft_get_max_pos(t_stack *stack);
void	ft_lstclear(t_stack **lst);
void	ft_free_stack(t_stack **stack);

/* operations */
void	ft_pa(t_stack **a, t_stack **b, t_bench *bench);
void	ft_pb(t_stack **a, t_stack **b, t_bench *bench);
void	ft_ra(t_stack **a, t_bench *bench);
void	ft_rb(t_stack **b, t_bench *bench);
void	ft_rra(t_stack **a, t_bench *bench);
void	ft_rrb(t_stack **b, t_bench *bench);
void	ft_sa(t_stack **a, t_bench *bench);
void	ft_sb(t_stack **b, t_bench *bench);
void	ft_rr(t_stack **a, t_stack **b, t_bench *bench);
void	ft_rrr(t_stack **a, t_stack **b, t_bench *bench);
void	ft_ss(t_stack **a, t_stack **b, t_bench *bench);
void	ft_print_op(char *op, t_bench *bench);

/* utils */
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
long	ft_atol(char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_free(char **new_av);
void	ft_assign_indices(t_stack *stack);
char	*ft_strdup(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_free_split(char **split);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* sort_simple */
void	ft_simple_sort(t_stack **a, t_stack **b, t_bench *bench);
void	ft_bubble_sort(t_stack **a, t_stack **b, t_bench *bench);
void	ft_sort_two(t_stack **a, t_bench *bench);
void	ft_sort_three(t_stack **a, t_bench *bench);
void	ft_bring_min_to_top(t_stack **a, int pos, t_bench *bench);

/* sort_block */
void	ft_block_sort(t_stack **a, t_stack **b, t_bench *bench);
int		ft_sqrt(int nb);
int		ft_find_in_chunk(t_stack *stack, int min, int max);
void	ft_push_chunk(t_stack **a, t_stack **b, int min, int max,t_bench *bench);
void	ft_optimize_b(t_stack **b, t_bench *bench);

/* sort_radix */
void	ft_radix_sort(t_stack **a, t_stack **b, t_bench *bench);
void	ft_bring_to_top(t_stack **stack, int pos, t_bench *bench, char name);

/* sort_adaptive */
void	ft_adaptive_sort(t_stack **a, t_stack **b, t_bench *bench);
void	ft_dispatch_sort(t_stack **a, t_stack **b, char *strat, t_bench *bch);
void	ft_sort_stacks(t_stack **a, t_stack **b, char *strat, t_bench *bch);

/* bench */
void	ft_init_bench(t_bench *bench);
void	ft_print_bench(t_bench *bench);
double	ft_compute_disorder(t_stack *stack);

#endif