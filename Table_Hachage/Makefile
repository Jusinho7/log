CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

NAME = hash

SRC = hachage.c function.c

OBJ = $(SRC:.c=.o)

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

valgrind: $(NAME)
	$(VALGRIND) ./$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re