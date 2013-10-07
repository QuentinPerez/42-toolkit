/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/07 04:18:37 by irabeson          #+#    #+#             */
/*   Updated: 2013/10/07 11:57:43 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_list_insert method>
** < insert >
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

#include <s_list.h>
#include <m_error.h>

t_list_cell	*f_list_insert(t_list *v_this, t_list_cell *position, void *data)
{
	t_list_cell	*cell;

	if (position == NULL)
	{
		if (D_LIST(push_back)(v_this, data) == true)
			return (D_LIST(end)(v_this));
		else
			return (NULL);
	}
	cell = D_CELL(create)(position->v_prev, position, data);
	if (cell != NULL)
	{
		if (position->v_prev != NULL)
			position->v_prev->v_next = cell;
		else
			v_this->v_begin = cell;
		position->v_prev = cell;
		v_this->v_size = v_this->v_size + 1;
	}
	else
		m_error("Bad alloc", (size_t)NULL);
	return (cell);
}
