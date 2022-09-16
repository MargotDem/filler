/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:27:12 by mde-maul          #+#    #+#             */
/*   Updated: 2022/09/16 18:27:13 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	place_piece(t_solution *solution)
{
	short	i;
	short	j;
	char			*str_x;
	char			*str_y;

	i = solution->i - solution->piece_square->y;
	j = solution->j - solution->piece_square->x;
	str_x = ft_itoa((int)j);
	str_y = ft_itoa((int)i);
	write(1, str_y, ft_strlen(str_y));
	write(1, " ", 1);
	write(1, str_x, ft_strlen(str_x));
	write(1, "\n", 1);
	free(str_x);
	free(str_y);
}
