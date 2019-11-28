/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:40:20 by etexier           #+#    #+#             */
/*   Updated: 2019/11/18 14:46:26 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*m;

	m = (char *)malloc(size + 1);
	if (m <= 0)
		return (NULL);
	ft_memset(m, 0, size + 1);
	return (m);
}
