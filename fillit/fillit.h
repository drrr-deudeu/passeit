/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:55:46 by etexier           #+#    #+#             */
/*   Updated: 2019/11/28 16:09:47 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef	struct				s_tetrino
{
	unsigned short int		shape;
	int						index[4];
	int						bounding[2];
	struct s_tetrino		*next;
}							t_tetrino;

# define SHAPE '#'
# define EMPTY '.'

# define TOO_MANY_EMPTY "File format error: too many empty lines\n"
# define BAD_TETRINO_DATA ".....Bad tetrino data\n"
# define USAGE1 "usage: ./fillit a_file\n"
# define USAGE2 "a_file: contain valid tetrino with an empty line separator\n"

# define CANNOT_READ_FILE "Cannot read file."

# define FILE_NOT_FORMA1 "tetrino: 4 lines with 4 blocks (only # and .)\n"
# define FILE_NOT_FORMA2 "tetrino: each blocks next to at least one\n"
# define FILE_NOT_FORMA3 "         one line to separate each tetrino\n"
# define FILE_NOT_FORMATED FILE_NOT_FORMA1 FILE_NOT_FORMA2 FILE_NOT_FORMA3

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
void						bound(unsigned short int i, int *x, int *y);

t_tetrino 					*add_to_list(t_tetrino **first, t_tetrino *new);
void 						free_tetrino_list(t_tetrino **ll);

void						print_line(unsigned char v);
void						print_tetrino(t_tetrino *l);
void						print_list(t_tetrino *l);

#endif
