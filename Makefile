NAME = push_swap
SRC = ft_split.c  push_swap.c reverse_rotate_algo.c  stack_check.c swap_operations.c \
help_functins.c node_handle.c rotate_operations.c stack_handle.c \
main.c push_operations.c  sorting_logic.c stack_init.c chunk_algo.c chunk_algo2.c \
chunk_algo3.c chunk_algo4.c

OBJ = $(SRC:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  $(FLAGS) $(OBJ) -o $(NAME) 

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re