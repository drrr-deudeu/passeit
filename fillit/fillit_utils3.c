/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 08:13:06 by etexier           #+#    #+#             */
/*   Updated: 2019/12/02 18:32:33 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

unsigned short int	*get_objects_local(void)
{
	static unsigned short int	shape_object[SHAPES_MAX] = {0xf000,
															0xe200,
															0xe400,
															0xe800,
															0xcc00,
															0xc600,
															0xc440,
															0xc880,
															0x8E00,
															0x8c80,
															0x8c40,
															0x88c0,
															0x8888,
															0x6c00,
															0x4E00,
															0x4C80,
															0x4460,
															0x4C40,
															0x2E00};

	return (shape_object);
}

unsigned short int	shift_left(unsigned short int tetrino)
{
	char	l1;
	char	l2;
	char	l3;
	char	l4;

	l1 = ((tetrino >> 12) << 1) & 0x000F;
	l2 = ((tetrino >> 8) << 1) & 0x000F;
	l3 = ((tetrino >> 4) << 1) & 0x000F;
	l4 = ((tetrino << 1) & 0x000F);
	tetrino = (l1 << 12) + (l2 << 8) + (l3 << 4) + l4;
	return (tetrino);
}

t_tetrino			*build_all_default(void)
{
	int					count;
	unsigned short int	*def;
	t_tetrino			*first;
	t_tetrino			*t;

	count = 0;
	first = NULL;
	def = get_objects_local();
	while (count < SHAPES_MAX)
	{
		t = make_s_tetrino(def[count]);
		if (t != NULL)
			add_to_list(&first, t);
		count++;
	}
	return (first);
}

int					is_valid_shape(unsigned short int t)
{
	int					count;
	unsigned short int	*def;

	count = 0;
	def = get_objects_local();
	while (count < SHAPES_MAX)
	{
		if (t == def[count])
			return (count);
		count++;
	}
	return (-1);
}

int					is_on(unsigned short int tetrino, int index)
{
	if (((tetrino >> (15 - index)) & 0x0001) == 1)
		return (1);
	return (0);
}
