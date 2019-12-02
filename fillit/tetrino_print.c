/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrino_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:55:13 by etexier           #+#    #+#             */
/*   Updated: 2019/12/02 13:05:22 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

void	print_line(unsigned char v)
{
	if (v & 0x08)
		ft_putchar(SHAPE);
	else
		ft_putchar(EMPTY);
	if (v & 0x04)
		ft_putchar(SHAPE);
	else
		ft_putchar(EMPTY);
	if (v & 0x02)
		ft_putchar(SHAPE);
	else
		ft_putchar(EMPTY);
	if (v & 0x01)
		ft_putchar(SHAPE);
	else
		ft_putchar(EMPTY);
}

void	print_bounding(t_tetrino *l, unsigned short int val)
{
	ft_putstr("val: ");
	ft_putnbr(val);
	ft_putstr(" width/height = ");
	ft_putnbr(l->bounding[0]);
	ft_putstr(", ");
	ft_putnbr(l->bounding[1]);
	ft_putchar('\n');
}

void	print_span(t_tetrino *l)
{
	int count;

	count = 0;
	ft_putstr("row\n");
	while (count < 4)
	{
		ft_putstr("start: ");
		ft_putnbr(l->spanx[count].start);
		ft_putstr(" span: ");
		ft_putnbr(l->spanx[count].span);
		ft_putstr("\n");
		count++;
	}
	count = 0;
	ft_putstr("col\n");
	while (count < 4)
	{
		ft_putstr("start: ");
		ft_putnbr(l->spany[count].start);
		ft_putstr(" span: ");
		ft_putnbr(l->spanx[count].span);
		ft_putstr("\n");
		count++;
	}
}

void	print_tetrino(t_tetrino *l, int style)
{
	unsigned short int val;

	if (l == NULL)
		return ;
	val = l->shape;
	print_line(val >> 12);
	ft_putchar('\n');
	print_line(val >> 8);
	ft_putchar('\n');
	print_line(val >> 4);
	ft_putchar('\n');
	print_line(val);
	ft_putchar('\n');
	if (style == 1)
		print_bounding(l, val);
	if (style == 2)
	{
		print_bounding(l, val);
		print_span(l);
	}
	else
		ft_putchar('\n');
}

void	print_list(t_tetrino *l, int style)
{
	while (l)
	{
		print_tetrino(l, style);
		l = l->next;
	}
}
