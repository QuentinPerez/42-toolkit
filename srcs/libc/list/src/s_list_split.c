/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/07 19:58:18 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/08 17:57:27 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_list_split method>
** < split >
** Copyright (C) <2013>  Iohann Rabeson <irabeson42@gmail.com>
**
** This file is part of 42-toolkit.
**
** 42-toolkit is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <list/s_list.h>
#include <stdlib.h>

static void	f_list_split_imp(t_list *v_this, t_list *new_list,
							t_list_cell *split_at)
{
	new_list->v_begin = split_at;
	new_list->v_end = D_LIST(end)(v_this);
	new_list->v_size = D_LIST_CELL(count)(split_at, D_LIST(end)(v_this));
	v_this->v_size = D_LIST(size)(v_this) - D_LIST(size)(new_list);
	v_this->v_end = D_LIST_CELL(prev)(split_at);
	v_this->v_end->v_next = NULL;
	new_list->v_begin->v_prev = NULL;
	new_list->v_end->v_next = NULL;
}

void		f_list_split(t_list *v_this, t_list_cell *split_at,
						t_list *new_list)
{
	if (new_list != NULL && split_at != NULL)
	{
		if (D_LIST(empty)(new_list) == false)
			D_LIST(clear)(new_list);
		if (D_LIST(begin)(v_this) == split_at)
		{
			new_list->v_begin = D_LIST(begin)(v_this);
			new_list->v_end = D_LIST(end)(v_this);
			new_list->v_size = D_LIST(size)(v_this);
			new_list->f_destroy = v_this->f_destroy;
			v_this->v_size = 0;
			v_this->v_begin = NULL;
			v_this->v_end = NULL;
			v_this->f_destroy = NULL;
		}
		else
			D_LIST(split_imp)(v_this, new_list, split_at);
	}
}
