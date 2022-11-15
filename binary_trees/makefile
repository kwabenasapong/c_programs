CC = gcc
NAME = result
CFLAGS = -Wall -Wextra -Werror -pedantic
SRC = 0-main.c 0-binary_tree_node.c binary_tree_print.c
OBJ = $(SRC:.c=.o)
RM = rm -f

.PHONY: all clean re

all:$(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ) $(NAME)

re: clean all

