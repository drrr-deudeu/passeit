#include <stdlib.h>
#include "fillit.h"

t_tetrino *add_to_list(t_tetrino **first, t_tetrino *new)
{
	t_tetrino *tmp;

	tmp = *first;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = new;
			return (*first);
		}
		tmp = tmp->next;
	}
	*first = new;
	return (*first);
}
