/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:26:45 by mde-maul          #+#    #+#             */
/*   Updated: 2022/09/16 18:26:53 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	handle_error(void)
{
	write(2, "error\n", 6);
	exit(1);
}

void	*handle_null(void *param)
{
	if (!param)
		handle_error();
	return (param);
}
