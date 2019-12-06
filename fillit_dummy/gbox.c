/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbox.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 10:51:05 by etexier           #+#    #+#             */
/*   Updated: 2019/12/04 10:51:43 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_gbox	*extend_box(t_gbox *b, int x, int y)
{
	if (x - b->x > b->sizex)
		b->sizex = x - b->x;
	if (y - b->y > b->sizey)
		b->sizey = y - b->y;
	return (b);
}

t_gbox	*init_box(t_gbox *b)
{
	b->x = 0;
	b->y = 0;
	b->sizex = 0;
	b->sizey = 0;
	return (b);
}
