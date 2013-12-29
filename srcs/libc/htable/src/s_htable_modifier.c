/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_htable_modifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/08 19:25:06 by qperez            #+#    #+#             */
/*   Updated: 2013/12/29 15:49:59 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_htable_modifier function>
** < add, get >
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

#include <htable/s_htable.h>
#include <f_string/f_string.h>
#include <list/s_list.h>
#include <f_error/m_error.h>

ui				f_htable_generate_key(const t_htable *v_this, const char *str);
t_htable_cell	*f_htable_create_cell(const char *key, void *data,
									  void (*f_delete)(void *data));

bool			f_htable_add(t_htable *v_this, const char *str, void *data)
{
	ui				key;
	t_list			*element;
	t_htable_cell	*cell;

	key = D_HTABLE(generate_key)(v_this, str);
	element = D_ARRAY(at)(&v_this->v_array, key, t_list *);
	cell = D_HTABLE(create_cell)(str, data, v_this->f_delete);
	if (cell == NULL)
		return (M_ERROR(false, "Bad alloc"));
	return (D_LIST(push_back)(element, cell));
}

void			*f_htable_get(t_htable *v_this, const char *str)
{
	t_list		*list;
	void		*ret;
	t_list_cell	*cell;

	ret = NULL;
	list = D_ARRAY(at)(&v_this->v_array,
					   D_HTABLE(generate_key)(v_this, str), t_list *);
	cell = D_LIST(begin)(list);
	while (cell != NULL && ret == NULL)
	{
		if (uf_strcmp(str, ((t_htable_cell*)cell->v_data)->v_key) == 0)
			ret = ((t_htable_cell*)cell->v_data)->v_data;
		cell = cell->v_next;
	}
	return (ret);
}
