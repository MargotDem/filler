# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 18:24:33 by mde-maul          #+#    #+#              #
#    Updated: 2022/09/16 18:24:35 by mde-maul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mde-maul.filler

FLAGS = -Werror -Wextra -Wall
LIBS = -L ./libft -lft

FILES = main.c				\
		gnl.c				\
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
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all
