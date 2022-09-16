/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:25:26 by mde-maul          #+#    #+#             */
/*   Updated: 2022/09/16 18:25:28 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_square(t_queue *queue, short value, t_grid_square *square)
{
	if (square->value == EMPTY)
	{
		push_queue(queue, square);
		square->value = value + 1;
	}
}

void	handle_square(t_data *data, t_grid_square *square, t_queue *queue)
{
	unsigned int	line;
	unsigned int	col;
	unsigned int	x;
	unsigned int	y;
	unsigned int	i;
	t_grid_square	*grid;

	line = data->line;
	col = data->col;
	x = square->x;
	y = square->y;
	grid = data->grid;
	if (y > 0)
	{
		i = y - 1;
		if (x > 0)
			check_square(queue, square->value, &grid[(col * i + x - 1)]);
		check_square(queue, square->value, &grid[(col * i + x)]);
		if (x + 1 < col)
			check_square(queue, square->value, &grid[(col * i + x + 1)]);
	}

	if (x > 0)
		check_square(queue, square->value, &grid[(col * y + x - 1)]);
	if (x + 1 < col)
		check_square(queue, square->value, &grid[(col * y + x + 1)]);

	if (y + 1 < line)
	{
		i = y + 1;
		if (x > 0)
			check_square(queue, square->value, &grid[(col * i + x - 1)]);
		check_square(queue, square->value, &grid[(col * i + x)]);
		if (x + 1 < col)
			check_square(queue, square->value, &grid[(col * i + x + 1)]);
	}
}

void	calc_dists(t_data *data)
{
	unsigned int	line;
	unsigned int	col;
	unsigned int	i;
	unsigned int	j;
	t_queue	*queue;

	line = data->line;
	col = data->col;
	i = 0;
	init_queue(&queue, 10);
	while (i < line)
	{
		j = 0;
		while (j < col)
		{
			if ((data->grid[(col * i) + j]).value == THEM)
				push_queue(queue, &(data->grid[(col * i) + j]));
			j++;
		}
		i++;
	}
	i = 0;
	while ((int)i < queue->counter)
	{
		handle_square(data, queue->arr[i], queue);
		i++;
	}
	free(queue->arr);
	free(queue);
}
