/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:42:21 by mde-maul          #+#    #+#             */
/*   Updated: 2022/09/18 18:42:23 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
