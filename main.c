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

short	get_map_data2(t_data *data)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = gnl(0, &line);
	if (ret == 0)
		return (0);
	if (ret < 1)
	{

		//panic("In player_data: get_map_data: GNL ret", data);
	}
	if (strncmp("Plateau", line, ft_strlen("Plateau")) != 0)
	{

		//panic("In get_map_data: get_map_data: Checking beginning", data);
	}
	data->line = ft_atoi(&line[8]);
	if (data->line < 1)
	{
		print_err("YO WHA TTHE FUCK\n");
		//panic("In get_map_data: get_map_data: line dimension", data);
	}
	data->col = ft_atoi(&line[8 + nb_len(data->line)]);
	if (data->col < 1)
		//panic("In get_map_data: get_map_data: col dimension", data);
	ft_strdel(&line);

	return (1);
}

void	get_map2(t_data *data)
{
	skip_line();
	get_lines(data->line, &data->map);
}


int	main(void)
{
	t_data	*data;
	t_piece	*piece;
	(void)piece;
	int		i;

	i = 0;
	data = init_data();

	get_player(data);

	while (get_map_data(data))
	{
		get_map(data);

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
