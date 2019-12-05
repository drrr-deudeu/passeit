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

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

int		is_candidate(t_grid *grid, int row, int col, t_tetrino *t)
{
	int		count;
	int		start;
	int		end;

	if ((row + t->box[1] > grid->csize) || (col + t->box[0] > grid->csize))
		return (0);
	count = 0;
	while (count < 4 && t->spanx[count].start != -1)
	{
		start = t->spanx[count].start;
		end = start + t->spanx[count].span;
		while (start < end)
		{
			if (grid->table[row + count][col + start] != EMPTY)
				return (0);
			start++;
		}
		count++;
	}
	return (1);
}

int		insert_tetrino(t_grid *grid, int row, int col, t_tetrino *t)
{
	int		count;
	int		start;
	int		end;

	count = 0;
	while (count < 4 && t->spanx[count].start != -1)
	{
		start = t->spanx[count].start;
		end = start + t->spanx[count].span;
		while (start < end)
		{
			grid->table[row + count][col + start] = grid->marker;
			start++;
		}
		count++;
	}
	grid->marker++;
	/*extend_box(&(grid->gbox), row + t->box[1], col + t->box[0]);*/
	return (1);
}

int		resize_up(t_grid *grid)
{
	if (grid->csize + 1 < GRID_SIZE_MAX)
	{
		grid->csize++;
		grid->marker = 65;
		ft_memset(&grid->table, EMPTY, GRID_SIZE_MAX * GRID_SIZE_MAX);
		return (1);
	}
	return (0);
}
