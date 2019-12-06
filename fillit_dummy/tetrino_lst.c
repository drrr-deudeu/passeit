/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrino_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:55:13 by etexier           #+#    #+#             */
/*   Updated: 2019/12/02 13:04:00 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

t_tetrino		*add_to_list(t_tetrino **first, t_tetrino *new)
{
	t_tetrino *tmp;

	tmp = *first;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = new;
			return (*first);
		}
		tmp = tmp->next;
	}
	*first = new;
	return (*first);
}
