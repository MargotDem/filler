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

	/*
	print_err("heooollooooo our symbol is\n");
	print_char_err(&data->symbol_us);
	print_char_err("\n");
	*/
	//write(1, "the fuckkkkk\n", 14);
	
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
	write(1, "va niquer ta daronne carli, cordialement\n", 50);
	free(data);
	system("leaks mde-maul.filler > ret_leaks.txt");
	return (0);
}


/*

ok j'ai exactlement 30 mins to come up with something to beat this bitch carli's ass
fuck you carli from the bottom of my heart

ok so we apparently get a spot in the bottom of the map and carly has a good spot or whatever
carly's a good af name ok FOCUS lmaoooo
i dont know what exaclty she does because i aint about to code a fucking visualizer for this bullshit project, i am 100% done
but maybe if i can implement some... "spread out" feature. because here shes close to us already so we focus on this small zone
instead of branching out. hooowww do we calc this....???
maybeeeyyyy. if we are right next to the attacker...? try and place it where you branch out...? idk.


ok on va encore se pieuter à 2h du mat tout va ienb tout va ienb its not like i was sane to begin with so...

i am at the end of my wits, at the fuck END i am telling you


what if
hvad med. ... do something where we calc starting position: if we are in a corner, eller vad vet jag. 
closer to the corner then the opponent, then we need to spread out quick instead of jsut giong towards them
yeah thats it tbh, right now we only considering the opponents position and not the whole board
mkay so how...?
we need to... place pieces the closer to the opponent, yes, but also, closer to the void. so calc not just how far it's from the opponent.
but also if it's in free space...?
but.. if you do that then you risk placing pieces "behind you"...?
aaa idk
mb save the most 3 best possiblities...?

oorrrr
maybe this way: we want to prevent them from "cutting us off"
so not just "the closest to the opponent" but "the closest AND the closest to the EDGE of the opponents pieces"...?





*/
