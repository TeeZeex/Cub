SRC =	get_next_line_bonus.c get_next_line_utils_bonus.c\

OBJ = $(SRC:.c=.o)

CC = gcc

NAME = getnextline.a

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re