/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:54:44 by etexier           #+#    #+#             */
/*   Updated: 2019/11/26 16:44:28 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

static t_fd_list	*rdata(int fd, t_fd_list **start)
{
	t_fd_list *fd_data;

	fd_data = *start;
	while (fd_data != NULL)
	{
		if (fd_data->fd == fd)
			break ;
		fd_data = fd_data->next;
	}
	if (fd_data == NULL)
	{
		fd_data = (t_fd_list*)ft_memalloc(sizeof(t_fd_list) + 1);
		if (fd_data == NULL)
			return (NULL);
		fd_data->fd = fd;
		if (*start == NULL)
			*start = fd_data;
		else
		{
			fd_data->next = (*start)->next;
			(*start)->next = fd_data;
		}
	}
	return (fd_data);
}

static void			my_realloc_copy(t_list *data, char *new_value)
{
	char	*ptr;
	size_t	size;

	if (data == NULL || new_value == NULL)
		return ;
	size = ft_strlen(new_value) + 1;
	if (data->content_size > size)
	{
		ft_memcpy(data->content, new_value, size);
		return ;
	}
	ptr = ft_strdup(new_value);
	if (ptr != NULL)
	{
		if (data->content != NULL)
			free(data->content);
		data->content = ptr;
		data->content_size = ft_strlen(ptr) + 1;
		while (*ptr)
		{
			if (!ft_isprint((int)(char)(*ptr)) && *ptr != '\n' && *ptr != '\t')
				*ptr = '\\';
			ptr++;
		}
	}
}

static char			*string_pop(t_fd_list *at, char **line)
{
	char	*ptr;
	int		size;

	if (at == NULL || at->data == NULL || at->data->content == NULL)
		return (NULL);
	ptr = ft_strchr(at->data->content, END_OF_LINE);
	if (ptr != NULL)
	{
		*ptr = '\0';
		size = (int)((unsigned int)ptr - (unsigned int)at->data->content + 1);
		if (line != NULL && *line != NULL)
			free(*line);
		*line = (char *)malloc(sizeof(char) * (size));
		ft_memcpy(*line, at->data->content, size);
		my_realloc_copy(at->data, (char *)(at->data->content + size));
		return (*line);
	}
	return (NULL);
}

static char			*string_push(t_fd_list *at, const char *buf,
								char **line, size_t count)
{
	char	*ptr;

	if (count == 0)
	{
		if (at->data->content_size == 0)
			return (NULL);
		if (line != NULL && *line != NULL)
			free(*line);
		*line = (char *)malloc(at->data->content_size);
		if (at->data->content != NULL)
			ft_memcpy(*line, at->data->content, at->data->content_size);
		free(at->data->content);
		at->data->content = NULL;
		at->data->content_size = 0;
		return (*line);
	}
	ptr = ft_strjoin((const char *)at->data->content, buf);
	if (ptr != NULL)
	{
		my_realloc_copy(at->data, ptr);
		free(ptr);
	}
	if (string_pop(at, line) != NULL)
		return (*line);
	return (NULL);
}

int					get_next_line(const int f, char **line)
{
	static t_fd_list	*start = NULL;
	t_fd_list			*at;
	char				*data;
	char				buffer[BUFF_SIZE + 1];
	size_t				count;

	if (f < 0 || f == 1 || f == 2 || !line || (at = rdata(f, &start)) == NULL)
		return (-1);
	if (at->data == NULL)
		at->data = ft_lstnew(0, 0);
	buffer[0] = '\0';
	data = string_pop(at, line);
	if (data != NULL)
		return (1);
	while ((count = read(f, buffer, BUFF_SIZE)) != 0)
	{
		buffer[count] = '\0';
		data = string_push(at, buffer, line, count);
		if (data != NULL)
			return (1);
	}
	data = string_push(at, buffer, line, 0);
	if (data != NULL && ft_strcmp(data, "") != 0)
		return (1);
	return (0);
}
