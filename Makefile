NAME = push_swap
CHEKER = checker

SRC = ft_split.c  push_swap.c reverse_rotate_algo.c  stack_check.c swap_operations.c \
help_functins.c node_handle.c rotate_operations.c stack_handle.c \
main.c push_operations.c  sorting_logic.c stack_init.c chunk_algo.c chunk_algo2.c \
chunk_algo3.c chunk_algo4.c help_functions2.c help_functions3.c

BONUS_SRC = checker.c get_next_line.c  get_next_line_utils.c help_functions2.c \
stack_check.c swap_operations.c help_functins.c node_handle.c rotate_operations.c stack_handle.c\
stack_init.c ft_split.c push_operations.c reverse_rotate_algo.c help_functions3.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)
OBJ = $(SRC:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  $(FLAGS) $(OBJ) -o $(NAME) 

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ 

bonus:$(CHEKER)

$(CHEKER): $(BONUS_SRC)
	$(CC)  $(FLAGS) $(BONUS_SRC) -o $(CHEKER) 

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -rf $(NAME) $(CHEKER)

re: fclean all

.PHONY: all clean fclean re