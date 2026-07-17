#include "dictionary.h"
#include "util.h"

t_dictionary	*create_dict(size_t size)
{
    t_dictionary    *dict;

    dict = malloc(sizeof (t_dictionary));
    if (dict == NULL)
		return (NULL);
	dict->size = 0;
	dict->capacity = size + 10;
	dict->items = malloc(dict->capacity * sizeof (t_dict_item));
	if (dict->items == NULL)
	{
		free(dict);
		return (NULL);
	}
	return (dict);
}

void			free_dict(t_dictionary	*dict)
{
	size_t	i;

	if (dict)
	{
		free(dict->items);
		free(dict);
	}
}

t_dictionary	*resize_dict(t_dictionary	*dict, size_t new_capacity)
{
	size_t		i;
	t_dict_item	*items;

	items = malloc(new_capacity * sizeof (t_dict_item));
	if (items == NULL)
		return (NULL);
	i = 0;
	while (i < dict->size)
	{
		items[i] = dict->items[i];
		i++;
	}
	free(dict->items);
	dict->items = items;
	dict->capacity = new_capacity;
	return (dict);
}

t_dict_item		*get_value(t_dictionary	*dict, t_key key)
{
	size_t	i;

	i = 0;
	while (i < dict->size)
	{
		if (dict->items[i].key == key)
			return (&dict->items[i]);
	}
	return (NULL);
}

t_dict_item		*set_value(t_dictionary	*dict, t_key key, char	*value)
{
	t_dict_item		*item;

	item = get_value(dict, key);
	if (item)
	{
		str_copy(item->value, value, MAX_COUNT + 1);
		return (item);
	}
	if (dict->size + 1 > dict->capacity)
	{
		if (resize_dict(dict, dict->capacity + 10) == NULL)
			return (NULL);
	}
	item = &dict->items[dict->size];
	item->key = key;
	str_copy(item->value, value, MAX_COUNT + 1);
	dict->size++;
	return (item);
}