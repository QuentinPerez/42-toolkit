/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_htable_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/09 08:21:59 by qperez            #+#    #+#             */
/*   Updated: 2013/10/09 12:01:42 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_htable_operator function>
** < erase, delete, remove_if >
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
#include <s_list.h>
#include <stddef.h>
#include <f_string.h>

ui		f_htable_generate_key(const t_htable *v_this, const char *str);

void	*f_htable_erase(t_htable *v_this, const char *key)
{
	t_list		*list;
	void		*ret;
	t_list_cell	*cell;

	ret = NULL;
	list = D_ARRAY(at)(&v_this->v_array,
					   D_HTABLE(generate_key)(v_this, key), t_list *);
	cell = D_LIST(begin)(list);
	while (cell != NULL && ret == NULL)
	{
		if (uf_strcmp(key, ((t_htable_cell*)cell->v_data)->v_key) == 0)
		{
			D_LIST(erase)(list, cell, &ret);
			ret = ((t_htable_cell*)ret)->v_data;
		}
		cell = cell->v_next;
	}
	return (ret);
}

void	f_htable_delete(t_htable *v_this, const char *key)
{
	t_list		*list;
	t_list_cell	*cell;

	list = D_ARRAY(at)(&v_this->v_array,
					   D_HTABLE(generate_key)(v_this, key), t_list *);
	cell = D_LIST(begin)(list);
	while (cell != NULL)
	{
		if (uf_strcmp(key, ((t_htable_cell*)cell->v_data)->v_key) == 0)
		{
			D_LIST(delete)(list, cell);
			break ;
		}
		cell = cell->v_next;
	}
}
