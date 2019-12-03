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
	t_span	*axe;
	int		stride;

	if ((x + t->box[0] > grid->csize) || (y + t->box[1] > grid->csize))
		return (0);
	count = 0;
	axe = t->spanx;
	stride = 1;
	if (t->box[0] < t->box[1])
	{
		axe = t->spany;
		stride = GRID_SIZE_MAX;
	}
	while (count < 4)
	{
		if (axe[count].start == -1)
			return(0);
	}
	return (1);
}
