#ifndef UTIL_H
# define UTIL_H
# include <unistd.h>
# define ERROR_NUM 1
# define DICT_ERROR_NUM 2
void    print_error(int	err);
size_t	str_copy(char	*dest, char	*src, size_t len);
#endif