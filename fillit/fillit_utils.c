/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:28:23 by etexier           #+#    #+#             */
/*   Updated: 2019/12/03 15:29:18 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_x(int i, int row_size)
{
    return (i % row_size);
}

int		get_y(int i, int row_size)
{
    return (i / row_size);
}

int		is_insertable(t_grid *grid, int grid_index, t_tetrino *t)
{
	int		x;
	int		y;
	int		offset;
	int		i;

	x = get_x(grid_index, grid->min_size);
	y = get_y(grid_index, grid->min_size);
	offset = x + t->spanx[0].start;
	if (grid->table[offset] != 0)
			return (0);

	i = 0;
	while (i < 4)
	{

		offset += (grid->min_size);
		i++;
	}
	return (1);
}