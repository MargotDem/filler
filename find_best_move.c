#include "filler.h"

t_solution	*create_solution(void)
{
	t_solution	*solution;

	solution = (t_solution *)handle_null(malloc(sizeof(t_solution)));
	solution->sum = 0;
	solution->piece_square = NULL;
	solution->i = 0;
	solution->j = 0;
	return (solution);
}

void	find_best_move(t_data *data, t_piece *piece)
{
	unsigned int	line;
	unsigned int	col;
	unsigned int	i;
	unsigned int	j;
	unsigned int	place;
	t_grid_square	*grid;
	t_solution		*solution;

	line = data->line;
	col = data->col;
	grid = data->grid;
	solution = create_solution();
	i = 0;

	while (i < line)
	{
		j = 0;
		while (j < col)
		{
			place = col * i + j;
			if ((grid[place]).value == US)
				try_piece(data, i, j, piece, solution);
			j++;
		}
		i++;
	}
	//place_piece_grid(solution, data);
	place_piece(solution);
	free(solution);
}
