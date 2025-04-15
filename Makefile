
CC = cc
CFLAGS = -Wall -Werror -Wextra -fPIE -g3
NAME = push_swap
INCLUDES = -I./includes -I./Libft
LIBFT = -L./Libft -lft

SRC = core/push_swap.c core/getters.c core/push.c core/reverse.c core/rotate.c core/swap.c core/add_node.c core/push_utils.c core/checker.c core/sort.c core/utils.c core/utils_2.c \
	  

OBJ = $(SRC:.c=.o)

all: libft $(NAME)

libft:
	@make -C Libft/

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c includes/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -f $(OBJ)
	@make clean -C Libft/

fclean: clean
	rm -f $(NAME)
	@make fclean -C Libft/

re: fclean all

.PHONY: all clean fclean re mlx libft