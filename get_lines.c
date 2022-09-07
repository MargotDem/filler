#include "filler.h"

void	get_lines(unsigned short nb_lines, char **dst)
{
	char	*line;
	size_t	i;
	char	*tmp;

	i = 0;
	while (i < nb_lines)
	{
		if (gnl(0, &line) < 1)
			handle_error();
		if (!(*dst))
		{
			*dst = ft_strdup(line);
			ft_strdel(&line);
			i++;
			continue ;
		}
		tmp = handle_null(ft_strjoin(*dst, line));
		ft_strdel(dst);
		ft_strdel(&line);
		*dst = tmp;
		i++;
	}
}
