NAME = mde-maul.filler

FLAGS = -Werror -Wextra -Wall
LIBS = -L ./libft -lft

FILES = main.c				\
		handle_error.c		\
		utils.c				\
		get_data.c			\
		get_lines.c			\
		queue.c				\
		calc_dists.c		\
		get_piece.c			\
		find_best_move.c	\
		try_piece.c			\
		place_piece.c		\
		create_grid.c		\
		gnl.c		\

OBJ_FILES = $(FILES:%.c=%.o)

all: $(NAME)

$(NAME):
	make -C ./libft
	gcc $(FLAGS) -c $(FILES)
	gcc $(FLAGS) -o $(NAME) $(OBJ_FILES) $(LIBS)

clean:
	make -C ./libft clean
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
