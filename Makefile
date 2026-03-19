NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_main.c \
       ft_main_utils.c \
	ft_main_utils2.c \
       ft_check_args.c \
       ft_check_utils.c \
       ft_stack_new.c \
       ft_stack_values.c \
       ft_stack_clear.c \
       ft_op_push.c \
       ft_op_rotate.c \
       ft_op_swap.c \
       ft_op_combined.c \
       ft_utils_split_atol.c \
       ft_utils_str.c \
       ft_utils_free.c \
       ft_utils_put.c \
       ft_bubble_sort.c \
       ft_sort_three.c \
       ft_sort_utils.c \
       ft_block_sort.c \
       ft_block_utils.c \
       ft_heap_sort.c \
       ft_adaptive_sort.c \
       ft_adaptive_utils.c \
       ft_bench_init.c \
       ft_bench_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

push_swap: $(OBJS)
	cc $(CFLAGS) $(OBJS) -o push_swap
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re