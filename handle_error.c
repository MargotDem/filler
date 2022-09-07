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
