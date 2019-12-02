/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:25:43 by etexier           #+#    #+#             */
/*   Updated: 2019/12/02 10:54:52 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

int				get_next_line(const int fd, char **line);

# ifndef BUFF_SIZE
#  define BUFF_SIZE 32
# endif

# define END_OF_LINE '\n'

#endif
