/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrix_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:37:51 by etexier           #+#    #+#             */
/*   Updated: 2019/11/28 16:12:44 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>
int				get_span(unsigned char val, int pos)
{
	if (pos == 3)
		return (1);
	if (pos == 2)
	{
		if (val == 3)
			return (2);
		return (1);
	}
	if (pos == 1)
	{
		if (val & 0x1)
			return (3);
		if (val & 0x10)
			return (2);
		return (1);
	}
	if (val & 0x1)
		return (4);
	if (val & 0x01)
		return (3);
	if (val & 0x100)
		return (2);
	return (1);
}

void			span_x(t_tetrino *t, int line, int *start, int *span)
{
	unsigned char val;
	int shift[4];

	shift[0]= 12;
	shift[1] = 8;
	shift[2] = 4;
	shift[3] = 0;
	val = 0;
	val = (unsigned char)((t->shape >> shift[line]) & 0x000F);
	*start = -1;
	*span = 0;
	if (val > 7)
		*start = 0;
	else if (val > 3)
		*start = 1;
	else if (val > 1)
		*start = 2;
	else if (val == 1)
		*start = 3;
	if (*start != -1)
		*span = get_span(val, *start);
}

int		test_insert(t_grid *grid, int offset_x, int offset_y, t_tetrino *t)
{
	int start;
	int span;
	int line;
	printf("grid max_size %d, offset = (%d,%d)", grid->min_size, offset_x, offset_y);
	while(t)
	{
		line = 0;
		print_tetrino(t, 1);
		while (line < 4)
		{
			span_x(t, line, &start, &span);
			printf("line %d, start %d, span %d\n", line, start, span);
			line++;
		}
		t = t->next;
	}
	return (1);
}
