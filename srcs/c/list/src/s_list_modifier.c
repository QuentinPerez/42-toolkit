/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/30 17:48:19 by qperez            #+#    #+#             */
/*   Updated: 2013/08/31 10:05:58 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This function contains all s_list_modifier method>
** < push_back, push_front >
** Copyright (C) <2013>  Quentin Perez <qperez42@gmail.com>
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

#include <s_list.h>
#include <m_error.h>

bool	f_list_push_back(t_list *v_this, void *data)
{
	t_cell	*cell;

	cell = D_CELL(create)(v_this->v_end, NULL, data);
	if (cell == NULL)
		return (m_error("Bad alloc", false));
	if (v_this->v_size == 0)
		v_this->v_begin = cell;
	else
		v_this->v_end->v_next = cell;
	v_this->v_end = cell;
	v_this->v_size = v_this->v_size + 1;
	return (true);
}

bool	f_list_push_front(t_list *v_this, void *data)
{
	t_cell	*cell;

	cell = D_CELL(create)(NULL, v_this->v_begin, data);
	if (cell == NULL)
		return (m_error("Bad alloc", false));
	if (v_this->v_size == 0)
		v_this->v_end = cell;
	else
		v_this->v_begin->v_prev = cell;
	v_this->v_begin = cell;
	v_this->v_size = v_this->v_size + 1;
	return (true);
}
