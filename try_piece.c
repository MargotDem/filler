#include "filler.h"

short	piece_fits(t_data *data, unsigned int i, unsigned int j, t_piece_list *piece)
{
	unsigned short	sum;
	t_grid_square	*grid;
	unsigned short	x;
	unsigned short	y;
	unsigned short	init_x;
	unsigned short	init_y;
	t_piece_list	*tmp;

	sum = 0;
	grid = data->grid;
	init_x = piece->x;
	init_y = piece->y;
	tmp = piece->next;
	while (tmp)
	{
		x = j + tmp->x - init_x;
		y = i + tmp->y - init_y;
		if (x < 0 || x >= data->col || y < 0 || y >= data->line || grid[data->col * y + x].value == US || grid[data->col * y + x].value == THEM)
		{
			return (0);
		}
		sum += grid[data->col * y + x].value;
		tmp = tmp->next;
	}
	tmp = piece->prev;
	while (tmp)
	{
		x = j + tmp->x - init_x;
		y = i + tmp->y - init_y;
		if (x < 0 || x >= data->col || y < 0 || y >= data->line || grid[data->col * y + x].value == US || grid[data->col * y + x].value == THEM)
		{
			return (0);
		}
		sum += grid[data->col * y + x].value;
		tmp = tmp->prev;
	}
	return (sum);
}

void	try_piece(t_data *data, unsigned int i, unsigned int j, t_piece *piece, t_solution *solution)
{
	t_piece_list	*list_el;
	t_grid_square	*grid;
	short	ret;

	list_el = piece->list;
	grid = data->grid;
	while (list_el)
	{
		ret = piece_fits(data, i, j, list_el);
		if (!solution->sum || (ret && ret < solution->sum))
		{
			solution->sum = ret;
			solution->piece_square = list_el;
			solution->i = i;
			solution->j = j;
		}
		list_el = list_el->next;
	}
}
