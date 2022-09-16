/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:25:35 by mde-maul          #+#    #+#             */
/*   Updated: 2022/09/16 18:25:36 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	create_grid(t_data *data)
{
	unsigned int	line;
	unsigned int	col;
	unsigned int	i;
	unsigned int	j;
	char			*ptr;

	data->grid = (t_grid_square *)handle_null(malloc(sizeof(t_grid_square) * data->col * data->line));
	line = data->line;
	col = data->col;
	i = 0;
	data->grid[0].value = 4;
	while (i < line)
	{
		j = 0;
		ptr = &(data->map[(col + 4) * i + 4]);
		while (j < col)
		{
			((data->grid)[(col * i) + j]).y = i;
			((data->grid)[(col * i) + j]).x = j;
			if (ptr[j] == data->symbol_us || ptr[j] == (data->symbol_us + 32))
				((data->grid)[(col * i) + j]).value = US;
			else if (ptr[j] == data->symbol_ennemy || ptr[j] == (data->symbol_ennemy + 32))
				((data->grid)[(col * i) + j]).value = THEM;
			else
				((data->grid)[(col * i) + j]).value = EMPTY;
			j++;
		}
		i++;
	}
}
