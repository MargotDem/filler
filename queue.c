/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:27:20 by mde-maul          #+#    #+#             */
/*   Updated: 2022/09/16 18:27:22 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_queue(t_queue **queue, int size)
{
	*queue = (t_queue *)(handle_null(malloc(sizeof(t_queue))));
	(*queue)->size = size;
	(*queue)->counter = 0;
	(*queue)->arr = \
		(t_grid_square **)(handle_null(malloc(sizeof(t_grid_square *) * size)));
	ft_bzero((void *)(*queue)->arr, sizeof(t_grid_square *) * size);
}

void	push_queue(t_queue *queue, t_grid_square *square)
{
	t_grid_square	**tmp;
	int				i;
	int				counter;
	int				size;

	counter = queue->counter;
	size = queue->size;
	if (counter && counter % size == 0)
	{
		tmp = (t_grid_square **)handle_null(malloc(sizeof(t_grid_square *) \
			* (counter + size)));
		ft_bzero((void *)tmp, sizeof(t_grid_square *) * (counter + size));
		i = 0;
		while (i < counter)
		{
			tmp[i] = queue->arr[i];
			i++;
		}
		free(queue->arr);
		queue->arr = tmp;
	}
	queue->arr[counter] = square;
	queue->counter = queue->counter + 1;
}
