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
	int		x;
	int		y;

	x = 0;
	while (x < grid->csize)
	{
		y = 0;
		while (y < grid->csize)
		{
			ft_putchar(grid->table[y][x]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
	ft_putchar('\n');
	return (1);
}

static int		insert_in_table(t_grid *grid, t_tetrino *t)
{
	int		x;
	int		y;

	x = grid->gbox.x;
	while (x < grid->csize)
	{
		y = grid->gbox.y;
		while (y < grid->csize)
		{
			if (is_candidate(grid, x, y, t))
			{
				insert_tetrino(grid, x, y, t);
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int				resolve_dummy(t_grid *grid)
{
	t_tetrino	*t;
	int			res;

	ft_putstr("in resolve result\n");
	ft_memset(&grid->table, '.', GRID_SIZE_MAX * GRID_SIZE_MAX);
	t = grid->tetrino_input;
	while (t)
	{
		res = insert_in_table(grid, t);
		display_result(grid);
		t = t->next;
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
