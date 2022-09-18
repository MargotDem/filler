/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:26:03 by mde-maul          #+#    #+#             */
/*   Updated: 2022/09/16 18:26:08 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_player(t_data *data)
{
	char	*line;

	line = NULL;
	if (gnl(0, &line) < 1)
		handle_error();
	data->us = ft_atoi(&line[10]);
	data->ennemy = (data->us == 1) + 1;
	ft_strdel(&line);
	data->symbol_us = 'X';
	data->symbol_ennemy = 'O';
	if (data->us == 1)
	{
		data->symbol_us = 'O';
		data->symbol_ennemy = 'X';
	}
}

short	get_map_data(t_data *data)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = gnl(0, &line);
	if (!ret)
		return (0);
	if (ret < 1)
		handle_error();
	data->line = ft_atoi(&line[8]);
	data->col = ft_atoi(&line[8 + nb_len(data->line)]);
	ft_strdel(&line);
	return (1);
}

void	get_map(t_data *data)
{
	skip_line();
	get_lines(data->line, &data->map);
}
