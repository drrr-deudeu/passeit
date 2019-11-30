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
	t_tetrino			*tmp;

	val = make_tetrino(b[0], b[1], b[2], b[3]);
	val = move_to_top(val);
	t = make_s_tetrino(val);
	if (t == NULL)
		return (0);
	if (*ll == NULL)
	{
		*ll = t;
		return (1);
	}
	tmp = *ll;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = t;
			return (1);
		}
		tmp = tmp->next;
	}
	return (1);
}

static t_tetrino		*clean_on_error(t_tetrino *lst_ttx)
{
	delete_list_tetrino(&lst_ttx);
	return (NULL);
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
		if (ft_strlen(line) == 4)
		{
			count_empty = 0;
			if (count_line < 4)
				b[count_line] = ft_strdup(line);
			count_line++;
		}
		else if (ft_strlen(line) == 0)
		{
			count_line = 0;
			count_empty++;
		}
		if (count_line == 4)
		{
			if (!add_tetrino(&lst_ttx, b))
				return (clean_on_error(lst_ttx));
			count_line = 0;
			count_empty = 0;
		}
		if (count_empty > 1)
		{
			write(STDERR_FILENO, TOO_MANY_EMPTY, sizeof(TOO_MANY_EMPTY));
			return (clean_on_error(lst_ttx));
		}
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
	print_list(lst_ttx);
	return (0);
}