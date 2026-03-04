NAME = push_swap
LIBFT_DIR = ./42-Libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I./includes

SRCS_DIR = ./srcs
SRCS = $(SRCS_DIR)/basic_functions.c \
       $(SRCS_DIR)/check_arguments.c \
       $(SRCS_DIR)/swap_functions.c \
       $(SRCS_DIR)/helper_functions.c \
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re