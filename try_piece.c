/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:27:31 by mde-maul          #+#    #+#             */
/*   Updated: 2022/09/16 18:27:32 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_square(t_data *data, unsigned int *ij, t_piece_list *tmp, \
	t_piece_list *piece)
{
	unsigned int	i;
	unsigned int	j;
	unsigned short	x;
	unsigned short	y;
	t_grid_square	*grid;

	i = ij[0];
	j = ij[1];
	x = j + tmp->x - piece->x;
	y = i + tmp->y - piece->y;
	grid = data->grid;
	if (x < 0 || x >= data->col || y < 0 || y >= data->line || \
		grid[data->col * y + x].value == US || \
		grid[data->col * y + x].value == THEM)
		return (0);
	return (1);
}

short	piece_fits(t_data *data, unsigned int *ij, t_piece_list *piece)
{
	unsigned short	sum;
	t_grid_square	*grid;
	t_piece_list	*tmp;

	sum = 0;
	grid = data->grid;
	tmp = piece->next;
	while (tmp)
	{
		if (!check_square(data, ij, tmp, piece))
			return (0);
		sum += grid[data->col * (ij[0] + tmp->y - piece->y) + \
			(ij[1] + tmp->x - piece->x)].value;
		tmp = tmp->next;
	}
	tmp = piece->prev;
	while (tmp)
	{
		if (!check_square(data, ij, tmp, piece))
			return (0);
		sum += grid[data->col * (ij[0] + tmp->y - piece->y) + \
			(ij[1] + tmp->x - piece->x)].value;
		tmp = tmp->prev;
	}
	return (sum);
}

void	try_piece(t_data *data, unsigned int *ij, \
	t_piece *piece, t_solution *solution)
{
	t_piece_list	*list_el;
	t_grid_square	*grid;
	short			ret;

	list_el = piece->list;
	grid = data->grid;
	while (list_el)
	{
		ret = piece_fits(data, ij, list_el);
		if (!solution->sum || (ret && ret < solution->sum))
		{
			solution->sum = ret;
			solution->piece_square = list_el;
			solution->i = ij[0];
			solution->j = ij[1];
		}
		list_el = list_el->next;
	}
}
