NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

MAIN_DIR = ./srcs/main
CHECK_DIR = ./srcs/check
STACK_DIR = ./srcs/stack
OPS_DIR = ./srcs/operations
UTILS_DIR = ./srcs/utils
SORT_SIMPLE_DIR = ./srcs/sort_simple
SORT_BLOCK_DIR = ./srcs/sort_block
SORT_HEAP_DIR = ./srcs/sort_heap
SORT_ADAPTIVE_DIR = ./srcs/sort_adaptive
BENCH_DIR = ./srcs/bench

SRCS = $(MAIN_DIR)/ft_main.c \
       $(MAIN_DIR)/ft_main_utils.c \
	   $(MAIN_DIR)/ft_main_utils2.c \
       $(CHECK_DIR)/ft_check_args.c \
       $(CHECK_DIR)/ft_check_utils.c \
       $(STACK_DIR)/ft_stack_new.c \
       $(STACK_DIR)/ft_stack_values.c \
       $(STACK_DIR)/ft_stack_clear.c \
       $(OPS_DIR)/ft_op_push.c \
       $(OPS_DIR)/ft_op_rotate.c \
       $(OPS_DIR)/ft_op_swap.c \
       $(OPS_DIR)/ft_op_combined.c \
       $(UTILS_DIR)/ft_utils_split_atol.c \
       $(UTILS_DIR)/ft_utils_str.c \
       $(UTILS_DIR)/ft_utils_free.c \
       $(UTILS_DIR)/ft_utils_put.c \
       $(SORT_SIMPLE_DIR)/ft_bubble_sort.c \
       $(SORT_SIMPLE_DIR)/ft_sort_three.c \
       $(SORT_SIMPLE_DIR)/ft_sort_utils.c \
       $(SORT_BLOCK_DIR)/ft_block_sort.c \
       $(SORT_BLOCK_DIR)/ft_block_utils.c \
       $(SORT_HEAP_DIR)/ft_heap_sort.c \
       $(SORT_ADAPTIVE_DIR)/ft_adaptive_sort.c \
       $(SORT_ADAPTIVE_DIR)/ft_adaptive_utils.c \
       $(BENCH_DIR)/ft_bench_init.c \
       $(BENCH_DIR)/ft_bench_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re