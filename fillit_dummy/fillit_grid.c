/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:52:23 by etexier           #+#    #+#             */
/*   Updated: 2019/12/02 18:49:51 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"
#include <stdio.h>

int				display_result(t_grid *grid)
{
	int		row;
	int		col;

	row = 0;
	while (row < grid->csize)
	{
		col = 0;
		while (col < grid->csize)
		{
			ft_putchar(grid->table[row][col]);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
	ft_putchar('\n');
	return (1);
}

static int		insert_in_table(t_grid *grid, t_tetrino *t)
{
	int		row;
	int		col;

	row = 0;
	while (row < grid->csize)
	{
		col = 0;
		while (col < grid->csize)
		{
			if (is_candidate(grid, row, col, t))
				return (insert_tetrino(grid, row, col, t));
			col++;
		}
		row++;
	}
	return (0);
}

int		insert_in_table_bt(t_grid *grid, t_tetrino *t, int row, int col)
{
	int		colvar;

	while (row < grid->csize)
	{
		colvar = col;
		while (colvar < grid->csize)
		{
			if (is_candidate(grid, row, colvar, t))
				return (insert_tetrino(grid, row, colvar, t));
			colvar++;
		}
		row++;
	}
	return (0);
}

int				resolve_dummy(t_grid *grid)
{
	t_tetrino	*t;
	int			res;

	ft_memset(&grid->table, EMPTY, GRID_SIZE_MAX * GRID_SIZE_MAX);
	t = grid->tetrino_input;
	while (t)
	{
		res = insert_in_table(grid, t);
		if (res == 0)
		{
			if (resize_up(grid) == 0)
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

int				get_csize(const t_grid *grid)
{
	int			count;
	int			res;
	t_tetrino	*data;

	data = grid->tetrino_input;
	count = 0;
	while (data)
	{
		data = data->next;
		count++;
	}
	res = 1;
	while ((res * res) <= (count * 4))
		res++;
	return (res);
}

t_grid			*init_grid(t_tetrino *lst)
{
	t_grid	*grid;

	grid = (t_grid *)malloc(sizeof(t_grid));
	if (grid == NULL)
		return (NULL);
	grid->marker = 65;
	grid->tetrino_input = lst;
	init_box(&grid->gbox);
	grid->csize = get_csize(grid);
	return (grid);
}
