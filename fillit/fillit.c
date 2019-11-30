/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:52:23 by etexier           #+#    #+#             */
/*   Updated: 2019/11/28 16:25:08 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"
#include "get_next_line.h"

static int				add_tetrino(t_tetrino **ll, char *b[4])
{
	unsigned short int	val;
	t_tetrino			*t;

	val = make_tetrino(b[0], b[1], b[2], b[3]);
	val = move_to_top(val);
	t = make_s_tetrino(val);
	if (t)
	{
		*ll = add_to_list(ll, t);
		return (1);
	}
	delete_list_tetrino(ll);
	return (0);
}

static void				check_buf(int *cl, int *ce, char *b[4], char *line)
{
	if (ft_strlen(line) == 4)
	{
		*ce = 0;
		if (*cl < 4)
			b[*cl] = ft_strdup(line);
		(*cl)++;
	}
	else if (ft_strlen(line) == 0)
	{
		(*cl) = 0;
		(*ce)++;
	}
}

static int				is_valid(int *cl, int *ce, char *b[4], t_tetrino **lst)
{
	if (*cl == 4)
	{
		if (!add_tetrino(lst, b))
		{
			write(STDERR_FILENO, BAD_TETRINO_DATA, sizeof(BAD_TETRINO_DATA));
			delete_list_tetrino(lst);
			print_list(build_all_default(), 0);
			return (0);
		}
		*cl = 0;
		*ce = 0;
	}
	if (*ce > 1)
	{
		write(STDERR_FILENO, TOO_MANY_EMPTY, sizeof(TOO_MANY_EMPTY));
		delete_list_tetrino(lst);
		return (0);
	}
	return (1);
}

static t_tetrino		*ft_fillit_reader(int fd)
{
	char		*line;
	char		*b[4];
	int			count_line;
	int			count_empty;
	t_tetrino	*lst_ttx;

	line = NULL;
	count_line = 0;
	count_empty = 0;
	lst_ttx = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		check_buf(&count_line, &count_empty, b, line);
		if (!is_valid(&count_line, &count_empty, b, &lst_ttx))
			return (NULL);
	}
	return (lst_ttx);
}

int						main(int argc, char **argv)
{
	int			fd;
	t_tetrino	*lst_ttx;

	if (argc != 2)
	{
		write(STDERR_FILENO, USAGE1, sizeof(USAGE1));
		write(STDERR_FILENO, USAGE2, sizeof(USAGE2));
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, CANNOT_READ_FILE, sizeof(CANNOT_READ_FILE));
		write(1, "\n", 1);
		return (1);
	}
	lst_ttx = ft_fillit_reader(fd);
	if (lst_ttx == NULL)
	{
		write(STDERR_FILENO, FILE_NOT_FORMATED, sizeof(FILE_NOT_FORMATED));
		return (1);
	}
	print_list(lst_ttx, 1);
	return (0);
}
