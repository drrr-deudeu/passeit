/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:37:46 by etexier           #+#    #+#             */
/*   Updated: 2019/11/12 18:46:34 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*uc_src;
	unsigned char	*uc_dst;
	unsigned char	*uc_tmp;
	unsigned char	*ptr_tmp;
	size_t			save_len;

	if (len == 0)
		return (dst);
	if (dst == NULL && src == NULL && len > 0)
		return (NULL);
	save_len = len;
	uc_tmp = (unsigned char *)malloc(len * sizeof(unsigned char));
	if (uc_tmp == NULL)
		return (dst);
	ptr_tmp = uc_tmp;
	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	while (len--)
		*ptr_tmp++ = *uc_src++;
	len = save_len;
	ptr_tmp = uc_tmp;
	while (len--)
		*uc_dst++ = *ptr_tmp++;
	free(uc_tmp);
	return (dst);
}
