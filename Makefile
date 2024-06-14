SRC = 	main.c error.c sets.c torch.c\
				Parsing/parse_utils.c Parsing/parsing.c Parsing/mapping.c Parsing/mapping_utils.c Parsing/texture.c \
				Execution/calculate.c Execution/draw.c Execution/draw2.c Execution/execution.c Execution/hooks.c\
				Execution/moves.c Execution/rays.c Execution/rays2.c\

NAME = cub3d

OBJ = $(SRC:.c=.o)

CC = CC

CFLAGS = -Wall -Wextra -Werror -g3

MLX = mlx/libmlx.a

LIB = libft/libft.a

GNL = ./libft/get_next_line/getnextline.a

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(OBJ): %.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(MLX) $(OBJ)
	@make -sC ./libft
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) $(GNL) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(MLX):
	@make -sC ./mlx

clean:
	@rm -f $(OBJ)
	@rm -f $(MLX)
	@make clean -sC ./mlx
	@make clean -sC ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -sC ./libft

re: fclean all
