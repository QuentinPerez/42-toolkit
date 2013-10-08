/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_htable_modifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/08 19:25:06 by qperez            #+#    #+#             */
/*   Updated: 2013/10/08 20:52:33 by qperez           ###   ########.fr       */
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

#include <s_htable.h>
#include <f_str_tools.h>
#include <f_string.h>
#include <s_list.h>
#include <stdlib.h>
#include <m_error.h>

static void				uf_cell_delete(void *data)
{
	(void)data;
}

static t_htable_cell	*f_htable_create_cell(const char *key, void *data,
											   void (*f_delete)(void *data))
{
	t_htable_cell	*cell;

	cell = malloc(sizeof(*cell));
	if (cell != NULL)
	{
		cell->v_key = uf_strdup(key);
		if (cell->v_key == NULL)
		{
			free(cell);
			return (NULL);
		}
		cell->v_data = data;
		cell->f_delete = uf_cell_delete;
		if (f_delete != NULL)
			cell->f_delete = f_delete;
	}
	return (cell);
}

static ui				f_htable_generate_key(const t_htable *v_this,
											  const char *str)
{
	ui	ret;
	ui	len;
	ui	i;
	ui	tmp;

	i = 0;
	ret = 0;
	len = uf_str_len(str);
	while (i < len)
	{
		ret = (ret << 4) + str[i];
		tmp = ret & 0xF0000000;
		if (tmp == 1)
		{
			ret = ret ^ (tmp >> 24);
			ret = ret ^ tmp;
		}
		i = i + 1;
	}
	return (ret % v_this->v_prime);
}

bool					f_htable_add(t_htable *v_this,
									 const char *str, void *data)
{
	ui				key;
	t_list			*element;
	t_htable_cell	*cell;

	key = D_HTABLE(generate_key)(v_this, str);
	element = D_ARRAY(at)(&v_this->v_array, key, t_list *);
	cell = D_HTABLE(create_cell)(str, data, v_this->f_delete);
	if (cell == NULL)
		return (m_error("Could not alloc cellule", (size_t)NULL));
	return (D_LIST(push_back)(element, cell));
}

void					*f_htable_get(t_htable *v_this, const char *str)
{
	ui		key;

	key = D_HTABLE(generate_key)(v_this, str);
	return ((void*)(size_t)key);
}
