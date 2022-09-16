/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:25:44 by mde-maul          #+#    #+#             */
/*   Updated: 2022/09/16 18:25:46 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include<unistd.h>
// delete
# include <stdio.h>

# define US -1
# define THEM 0
# define EMPTY -10

typedef struct s_piece_list {
	struct s_piece_list	*next;
	struct s_piece_list	*prev;
	unsigned short		x;
	unsigned short		y;
} t_piece_list;

typedef struct s_piece {
	unsigned short	line;
	unsigned short	col;
	char			*piece;
	t_piece_list	*list;
} t_piece;

typedef struct s_grid_square {
	unsigned short	x;
	unsigned short	y;
	short	value;
} t_grid_square;

typedef struct s_data
{
	unsigned short	us;
	unsigned short	ennemy;
	char			symbol_us;
	char			symbol_ennemy;
	unsigned int	line;
	unsigned int	col;
	char			*map;
	t_grid_square	*grid;
}	t_data;

typedef struct s_queue {
	int	counter;
	int	size;
	t_grid_square	**arr;
}	t_queue;

typedef struct s_solution {
	unsigned short	sum;
	t_piece_list	*piece_square;
	unsigned short	i;
	unsigned short	j;
}	t_solution;

# define BUFF_SIZE 200
# define FD_SIZE 4096

void	*handle_null(void *param);
void	handle_error(void);
void	print_err(char *str);
void	print_map(t_data *data);
void	print_char_err(char *str);
void	skip_line(void);
void	get_player(t_data *data);
short	get_map_data(t_data *data);
void	get_map(t_data *data);
void	create_grid(t_data *data);
void	init_queue(t_queue **queue, int size);
void	push_queue(t_queue *queue, t_grid_square *square);
void	find_best_move(t_data *data, t_piece *piece);
void	try_piece(t_data *data, unsigned int i, unsigned int j, t_piece *piece, t_solution *solution);
void	calc_dists(t_data *data);
t_piece	*get_piece(void);
int		nb_len(int n);
void	get_lines(unsigned short nb_lines, char **dst);
void	place_piece(t_solution *solution);
int		gnl(const int fd, char **line);

#endif
