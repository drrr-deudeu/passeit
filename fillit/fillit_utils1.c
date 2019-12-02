/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:24:46 by etexier           #+#    #+#             */
/*   Updated: 2019/11/28 15:44:32 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

void				delete_list_tetrino(t_tetrino **lst)
{
	t_tetrino	*tmp;
	t_tetrino	*next;

	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}

t_tetrino			*alloc_struct_tetrino(int *tmp, unsigned short int shape)
{
	t_tetrino	*ptr;
	int			index;

	ptr = (t_tetrino *)malloc(sizeof(t_tetrino));
	if (ptr == NULL)
		return (NULL);
	ptr->shape = shape;
	ptr->next = NULL;
	index = 0;
	while (index < 4)
	{
		ptr->index[index] = tmp[index];
		index++;
	}
	bound(shape, ptr->bounding, ptr->bounding + 1);
	do_span(ptr);
	return (ptr);
}

t_tetrino			*make_s_tetrino(unsigned short int t)
{
	int tmp[4];
	int index;
	int count;

	index = 0;
	count = 0;
	while (count < 16)
	{
		if (is_on(t, count) == 1)
		{
			if (index >= 4)
				return (0);
			tmp[index] = count;
			index++;
		}
		count++;
	}
	if (index != 4)
		return (NULL);
	if (!is_valid_shape(t))
		return (NULL);
	return (alloc_struct_tetrino(tmp, t));
}

unsigned short int	get_single_row_val(char *a_row)
{
	int			count;
	short int	res;

	res = 0;
	count = 0;
	while (count < 4)
	{
		if (a_row[count] == SHAPE)
			res = (res << 1) + 1;
		else
			res = (res << 1);
		count++;
	}
	return (res);
}

unsigned short int	add_tetrino_line(unsigned short val, char *a_row)
{
	return ((val << 4) + get_single_row_val(a_row));
}
