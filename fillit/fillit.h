/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:55:46 by etexier           #+#    #+#             */
/*   Updated: 2019/12/02 14:04:18 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef	struct				s_span
{
	int						start;
	int						span;
}							t_span;

typedef	struct				s_tetrino
{
	unsigned short int		shape;
	int						index[4];
	int						bounding[2];
	t_span					spanx[4];
	t_span					spany[4];
	struct s_tetrino		*next;
}							t_tetrino;

typedef struct				s_grid
{
	t_tetrino				*tetrino_input;
	int						min_size;
}							t_grid;

# define SHAPE '#'
# define EMPTY '.'

# define TOO_MANY_EMPTY "File format error: too many empty lines\n"
# define BAD_TETRINO_DATA "Bad tetrino data. Check valid:\n"
# define USAGE1 "usage: ./fillit a_file\n"
# define USAGE2 "a_file: contain valid tetrino with an empty line separator\n"

# define CANNOT_RD_FILE "Cannot read file.\n"

# define FILE_NOT_FORMAT "Wrong Format\n"

# define SHAPES_MAX 19

void						delete_list_tetrino(t_tetrino **lst);
t_tetrino					*alloc_struct_tetrino(int *d, unsigned short int s);
t_tetrino					*make_s_tetrino(unsigned short int t);
unsigned short int			get_single_row_val(char *a_row);
unsigned short int			add_tetrino_line(unsigned short val, char *a_row);

unsigned short int			move_to_top(unsigned short int tetrino);
unsigned short int			move_down(unsigned short int tetrino);
unsigned short int			move_right(unsigned short int tetrino);
unsigned short int			make_tetrino(char *a, char *b, char *c, char *d);

unsigned short int			shift_left(unsigned short int t);
t_tetrino					*build_all_default(void);
int							is_valid_shape(unsigned short int t);
int							is_on(unsigned short int tetrino, int index);

int							max_x(unsigned short int t);
int							min_y(unsigned short int t);
void						bound_x(unsigned short int i, int *x);
void						bound_y(unsigned short int t, int *y);
void						bound(unsigned short int i, int *x, int *y);

t_tetrino					*add_to_list(t_tetrino **first, t_tetrino *new);

void						print_line(unsigned char v);
void						print_tetrino(t_tetrino *l, int style);
void						print_bounding(t_tetrino *l, unsigned short int v);
void						print_span(t_tetrino *l);
void						print_list(t_tetrino *l, int style);

int							get_min_size(const t_grid *grid);
t_grid						*init_grid(t_tetrino *lst);

void						do_span(t_tetrino *t);
void						span_x(t_tetrino *t, int line, int *st, int *span);
int							get_xspan(unsigned char val, int pos);
void						span_y(t_tetrino *t, int col, int *st, int *span);
int							get_yspan(unsigned int u, int col, int *s, int pos);

#endif
