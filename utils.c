/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:27:39 by mde-maul          #+#    #+#             */
/*   Updated: 2022/09/16 18:27:41 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	skip_line(void)
{
	char	*line;

	line = NULL;
	if (gnl(0, &line) < 1)
		handle_error();
	ft_strdel(&line);
}

void	print_err(char *str)
{
	write(2, str, ft_strlen(str));
}

void	print_char_err(char *str)
{
	write(2, str, 1);
}

void	print_map(t_data *data)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;

	i = 0;
	while (i < data->line)
	{
		j = 0;
		ptr = &(data->map[(data->col + 4) * i + 4]);
		while (j < data->col)
		{
			print_char_err(&ptr[j]);
			print_char_err(" ");
			j++;
		}
		print_err("\n");
		i++;
	}
}

int	nb_len(int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
