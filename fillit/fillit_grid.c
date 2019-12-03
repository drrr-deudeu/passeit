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

int				display_result(t_grid *grid)
{
	int		x;
	int		y;

	ft_putstr("in display result\n");
	x = 0;
	while (x < grid->min_size)
	{
		y = 0;
		while (y < grid->min_size)
		{
			ft_putchar(grid->table[x][y]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
	ft_putchar('\n');
	return (1);
}

int				insert_to_table(t_grid *grid, t_tetrino *t)
{
	ft_putnbr(grid->min_size);
	ft_putnbr(t->base_shape);
	ft_putchar('\n');
	/*grid->table[t->index[0]]*/
	return (1);
}

int				resolve_dummy(t_grid *grid)
{
	t_tetrino	*t;

	ft_putstr("in resolve result\n");
	/*if (grid->table != NULL)
		free(grid->table);
	grid->table = (char *)malloc(sizeof(char) *
							grid->min_size * grid->min_size);*/
	ft_memset(&grid->table, 48, 15 * 15);
	t = grid->tetrino_input;
	while (t)
	{
		insert_to_table(grid, t);
		t = t->next;
	}
	return (1);
}

int				get_min_size(const t_grid *grid)
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
	grid->tetrino_input = lst;
	grid->min_size = get_min_size(grid);
	return (grid);
}
