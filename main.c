/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:26:58 by mde-maul          #+#    #+#             */
/*   Updated: 2022/09/16 18:27:00 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)handle_null((void *)malloc(sizeof(t_data)));
	data->us = 0;
	data->ennemy = 0;
	data->line = 0;
	data->col = 0;
	data->map = NULL;
	data->grid = NULL;
	return (data);
}

void	free_piece(t_piece **piece)
{
	t_piece_list	*next;

	if (piece && *piece)
	{
		while ((*piece)->list)
		{
			next = (*piece)->list->next;
			free((*piece)->list);
			(*piece)->list = next;
		}
		ft_strdel(&((*piece)->piece));
		free(*piece);
		*piece = NULL;
	}
}

void	free_grid(t_grid_square **grid)
{
	if (grid && *grid)
	{
		free(*grid);
		*grid = NULL;
	}
}

int	main(void)
{
	t_data	*data;
	t_piece	*piece;
	int		i;

	i = 0;
	data = init_data();
	get_player(data);
	while (get_map_data(data))
	{
		get_map(data);
		data->grid = \
		(t_grid_square *)handle_null(malloc(sizeof(t_grid_square) \
		* data->col * data->line));
		create_grid(data);
		calc_dists(data);
		piece = get_piece();
		find_best_move(data, piece);
		free_grid(&data->grid);
		free_piece(&piece);
		ft_strdel(&(data->map));
		i++;
	}
	free(data);
	system("leaks mde-maul.filler > ret_leaks.txt");
	return (0);
}
