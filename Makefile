NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_adaptive_sort.c \
       ft_bench_init.c \
       ft_bench_utils.c \
       ft_block_sort.c \
       ft_block_utils.c \
       ft_bubble_sort.c \
       ft_check_args.c \
       ft_check_utils.c \
       ft_main_utils.c \
       ft_main_utils2.c \
       ft_main.c \
       ft_op_combined.c \
       ft_op_push.c \
       ft_op_rotate.c \
       ft_op_swap.c \
       ft_radix_sort.c \
       ft_stack_new.c \
       ft_stack_values.c \
       ft_utils_put_and_str.c \
       ft_utils_split_atol.c

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