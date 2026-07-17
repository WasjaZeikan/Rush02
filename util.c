#include "util.h"
#define ERROR_MSG "Error\n"
#define DICT_ERROR_MSG "Dict Error\n"

void    print_error(int err)
{
	if (err == DICT_ERROR_NUM)
	{
		write(STDERR_FILENO, DICT_ERROR_MSG, 11);
		return ;
	}
	write(STDERR_FILENO, ERROR_MSG, 6);
}

size_t	str_copy(char	*dest, char	*src, size_t len)
{
	
}