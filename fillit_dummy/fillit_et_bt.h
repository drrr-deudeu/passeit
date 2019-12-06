/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_et_bt.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:55:46 by etexier           #+#    #+#             */
/*   Updated: 2019/12/02 18:50:59 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_ET_BT_H
# define FILLIT_ET_BT_H

#include "fillit.h"

typedef	struct				s_etbt
{
	int						start_row;
	int						start_col;
	struct s_tetrino		*data;
}							s_etbt;

#endif