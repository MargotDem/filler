/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:25:52 by mde-maul          #+#    #+#             */
/*   Updated: 2022/09/16 18:25:54 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	unsigned int	ij[2];
	unsigned int	place;
	t_grid_square	*grid;
	t_solution		*solution;

	grid = data->grid;
	solution = create_solution();
	ij[0] = 0;
	while (ij[0] < data->line)
	{
		ij[1] = 0;
		while (ij[1] < data->col)
		{
			place = data->col * ij[0] + ij[1];
			if ((grid[place]).value == US)
				try_piece(data, ij, piece, solution);
			(ij[1])++;
		}
		(ij[0])++;
	}
	place_piece(solution);
	free(solution);
}
