/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrix_bound.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:37:51 by etexier           #+#    #+#             */
/*   Updated: 2019/11/28 16:12:44 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			max_x(unsigned short int t)
{
	int max;

	max = 4;
	if (!is_on(t, 3) && !is_on(t, 7) && !is_on(t, 11) && !is_on(t, 15))
	{
		max--;
		if (!is_on(t, 2) && !is_on(t, 6) && !is_on(t, 10) && !is_on(t, 14))
		{
			max--;
			if (!is_on(t, 1) && !is_on(t, 5) && !is_on(t, 9) && !is_on(t, 13))
				max--;
		}
	}
	return (max);
}

int			min_y(unsigned short int t)
{
	int miy;

	miy = 1;
	if ((t & 0xF000) == 0)
	{
		miy++;
		if ((t & 0xFF00) == 0)
		{
			miy++;
			if ((t & 0xFFF0) == 0)
				miy++;
		}
	}
	return (miy);
}

void		bound_x(unsigned short int t, int *x)
{
	int mix;

	mix = 1;
	if (!is_on(t, 0) && !is_on(t, 4) && !is_on(t, 8) && !is_on(t, 12))
	{
		mix++;
		if (!is_on(t, 1) && !is_on(t, 5) && !is_on(t, 9) && !is_on(t, 13))
		{
			mix++;
			if (!is_on(t, 2) && !is_on(t, 6) && !is_on(t, 10) && !is_on(t, 14))
				mix++;
		}
	}
	*x = max_x(t) - mix + 1;
}

void		bound_y(unsigned short int t, int *y)
{
	int may;

	may = 4;
	if ((t & 0x000F) == 0)
	{
		may--;
		if ((t & 0x00FF) == 0)
		{
			may--;
			if ((t & 0x0FFF) == 0)
				may--;
		}
	}
	*y = may - min_y(t) + 1;
}

void		bound(unsigned short int t, int *x, int *y)
{
	bound_x(t, x);
	bound_y(t, y);
}
