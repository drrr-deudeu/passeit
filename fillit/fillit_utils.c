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

int		check_line(char *ptr, t_tetrino *t, int lline)
{
	int		start;
	int		end;

	start = t->spanx[lline].start;
	end = start + t->spanx[lline].span;
	ptr = ptr + start;
	while (start < end)
	{
		if (*ptr != EMPTY)
			return (0);
		ptr++;
		start++;
	}
	return (1);
}

int		write_line(char *ptr, t_tetrino *t, int lline, int marker)
{
	int		start;
	int		end;

	start = t->spanx[lline].start;
	end = start + t->spanx[lline].span;
	ptr = ptr + start;
	while (start < end)
	{
		*ptr = marker;
		ptr++;
		start++;
	}
	return (1);
}

int		is_candidate(t_grid *grid, int x, int y, t_tetrino *t)
{
	int		count;
	int		start;
	int		end;

	if ((x + t->box[0] >= grid->csize) || (y + t->box[1] >= grid->csize))
		return (0);
	count = 0;
	while (count < 4 && t->spanx[count].start != -1)
	{
		start = t->spanx[count].start;
		end = start + t->spanx[count].span;
		while (start < end)
		{
			if (grid->table[x + start][y + count] != EMPTY)
				return (0);
			start++;
		}
		
		count++;
	}
	return (1);
}

int		insert_tetrino(t_grid *grid, int x, int y, t_tetrino *t)
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
			grid->table[x + start][y + count] = grid->marker;
			start++;
		}
		count++;
	}
	grid->marker++;
	extend_box(&(grid->gbox), x + t->box[0], y + t->box[1]);
	return (1);
}
