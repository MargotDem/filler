/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:26:27 by mde-maul          #+#    #+#             */
/*   Updated: 2022/09/16 18:26:28 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	add_block(t_piece_list *list, t_piece_list *new)
{
	t_piece_list	*prev;

	while (list)
	{
		prev = list;
		list = list->next;
	}
	prev->next = new;
	new->prev = prev;
}

void	handle_new_block(unsigned short i, unsigned short j, t_piece *piece)
{
	t_piece_list	*piece_list_el;

	piece_list_el = \
		(t_piece_list *)handle_null(malloc(sizeof(t_piece_list)));
	piece_list_el->next = NULL;
	piece_list_el->prev = NULL;
	piece_list_el->x = j;
	piece_list_el->y = i;
	if (!piece->list)
		piece->list = piece_list_el;
	else
		add_block(piece->list, piece_list_el);
}

void	make_list(t_piece *piece)
{
	unsigned short	i;
	unsigned short	j;
	unsigned short	line;
	unsigned short	col;

	line = piece->line;
	col = piece->col;
	i = 0;
	while (i < line)
	{
		j = 0;
		while (j < col)
		{
			if (piece->piece[(i * col) + j] == '*')
				handle_new_block(i, j, piece);
			j++;
		}
		i++;
	}
}

t_piece	*create_piece(void)
{
	t_piece	*new;

	new = (t_piece *)handle_null(malloc(sizeof(t_piece)));
	ft_bzero(new, sizeof (t_piece));
	new->line = 0;
	new->col = 0;
	new->piece = 0;
	new->list = 0;
	return (new);
}

t_piece	*get_piece(void)
{
	char	*line;
	t_piece	*piece;

	line = NULL;
	if (gnl(0, &line) < 1)
		handle_error();
	piece = create_piece();
	piece->line = ft_atoi(&line[6]);
	piece->col = ft_atoi(&line[6 + nb_len(piece->line)]);
	ft_strdel(&line);
	get_lines(piece->line, &piece->piece);
	make_list(piece);
	return (piece);
}
