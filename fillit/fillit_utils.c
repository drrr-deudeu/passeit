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

	start = t->spanx[lline].start;
	while (start < t->spanx[lline].span)
	{
		if (*ptr != EMPTY)
			return (0);
		ptr++;
		start++;
	}
	return (1);
}

int		check_col(char *ptr, int stride, t_tetrino *t, int lline)
{
	int		start;

	start = t->spany[lline].start;
	while (start < t->spany[lline].span)
	{
		if (*ptr != EMPTY)
			return (0);
		ptr += stride;
		start++;
	}
	return (1);
}

int		is_candidate(t_grid *grid, int x, int y, t_tetrino *t)
{
	int		count;

	if ((x + t->box[0] > grid->csize) || (y + t->box[1] > grid->csize))
		return (0);
	count = 0;
	while (count < 4)
	{
		if (t->spanx[count].start == -1)
			return(1);
		if (!check_line(&(grid->table[x][y]), t, count))
			return (0);
		count++;
	}
	return (1);
}
