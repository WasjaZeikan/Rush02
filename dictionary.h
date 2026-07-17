#ifndef DICTIONARY_H
#define DICTIONARY_H
#define MAX_COUNT 50

#include <stdint.h>
#include <stdlib.h>

typedef	char t_value[MAX_COUNT + 1];
typedef	int64_t	t_key;

typedef struct s_dict_item
{
	t_key key;
	t_value value;

} t_dict_item;

typedef struct s_dictionary
{
	size_t	size;
	size_t	capacity;
	t_dict_item *items;
} t_dictionary;

t_dictionary	*create_dict(size_t size);
void			free_dict(t_dictionary	*dict);
t_dictionary	*resize_dict(t_dictionary	*dict, size_t new_capacity);
t_dict_item		*get_value(t_dictionary	*dict, t_key key);
t_dict_item		*set_value(t_dictionary	*dict, t_key key, char	*value);
#endif