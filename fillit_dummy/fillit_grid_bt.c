/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_grid_bt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:52:23 by etexier           #+#    #+#             */
/*   Updated: 2019/12/02 18:49:51 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "libft.h"
#include "fillit_et_bt.h"

int				resize_up_e_bt(t_grid *grid)
{
	/* first play with the index of each tetrino */
	if (grid->csize + 1 < GRID_SIZE_MAX)
	{
		grid->csize++;
		grid->marker = 65;
		ft_memset(&grid->table, EMPTY, GRID_SIZE_MAX * GRID_SIZE_MAX);
		return (1);
	}
	return (0);
}


int				insert_in_table_e_bt(t_grid *grid, t_tetrino *t, int r, int c)
{
	int		colvar;

	while (r < grid->csize)
	{
		colvar = c;
		while (colvar < grid->csize)
		{
			if (is_candidate(grid, r, colvar, t))
				return (insert_tetrino(grid, r, colvar, t));
			colvar++;
		}
		r++;
	}
	return (0);
}

int				resolve_e_bt(t_grid *grid)
{
	t_tetrino	*t;
	int			res;

	ft_memset(&grid->table, EMPTY, GRID_SIZE_MAX * GRID_SIZE_MAX);
	t = grid->tetrino_input;
	while (t)
	{
		res = insert_in_table_e_bt(grid, t, t->index[0], t->index[1]);
		if (res == 0)
		{
			if (resize_up_e_bt(grid) == 0)
				return (0);
			else
				t = grid->tetrino_input;
		}
		else
		{
			display_result(grid);
			t = t->next;
		}
	}
	return (1);
}

static int		get_csize_bt(const t_grid *grid)
{
	int			count;
	int			res;
	t_tetrino	*data;

	data = grid->tetrino_input;
	count = 0;
	while (data)
	{
		data->shape = count;
		ft_memset(data->index, 0, sizeof(int) * 4);
		data = data->next;
		count++;
	}
	res = 1;
	while ((res * res) <= (count * 4))
		res++;
	return (res);
}

t_grid			*init_grid_bt(t_tetrino *lst)
{
	t_grid	*grid;

	grid = (t_grid *)malloc(sizeof(t_grid));
	if (grid == NULL)
		return (NULL);
	grid->marker = 65;
	grid->tetrino_input = lst;
	init_box(&grid->gbox);
	grid->csize = get_csize_bt(grid);
	return (grid);
}