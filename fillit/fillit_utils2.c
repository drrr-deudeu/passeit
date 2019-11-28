/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:31:02 by etexier           #+#    #+#             */
/*   Updated: 2019/11/28 15:45:16 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short int	move_to_top(unsigned short int tetrino)
{
	int		count;

	count = 0;
	while (count < 3)
	{
		if ((tetrino & 0xF000) == 0)
			tetrino = tetrino << 4;
		count++;
	}
	count = 0;
	while (count < 3)
	{
		if (is_on(tetrino, 0) == 0 && is_on(tetrino, 4) == 0 &&
			is_on(tetrino, 8) == 0 && is_on(tetrino, 12) == 0)
			tetrino = shift_left(tetrino);
		count++;
	}
	return (tetrino);
}

unsigned short int	move_down(unsigned short int tetrino)
{
	if ((tetrino & 0x000F) == 0)
		tetrino = tetrino >> 4;
	return (tetrino);
}

unsigned short int	move_right(unsigned short int tetrino)
{
	char l1;
	char l2;
	char l3;
	char l4;

	if (is_on(tetrino, 3) == 0 &&
		is_on(tetrino, 7) == 0 && is_on(tetrino, 11) == 0 &&
		is_on(tetrino, 15) == 0)
	{
		l1 = ((tetrino >> 12) >> 1) & 0x000F;
		l2 = ((tetrino >> 8) >> 1) & 0x000F;
		l3 = ((tetrino >> 4) >> 1) & 0x000F;
		l4 = ((tetrino) >> 1) & 0x000F;
		tetrino = (l1 << 12) + (l2 << 8) + (l3 << 4) + l4;
	}
	return (tetrino);
}

unsigned short int	make_tetrino(char *row1,
								char *row2,
								char *row3,
								char *row4)
{
	return (add_tetrino_line(
			add_tetrino_line(
			add_tetrino_line(
			add_tetrino_line(0, row1), row2), row3), row4));
}
