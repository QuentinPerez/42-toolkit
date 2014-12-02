/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack_modifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 17:18:23 by qperez            #+#    #+#             */
/*   Updated: 2014/12/02 11:28:59 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_stack_modifier function>
** < push, pop >
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

#include <stack/s_stack.h>
#include <f_error/m_error.h>
#include <f_secure/f_secure.h>

static t_stack_cell	*f_stack_create_cell(void *data)
{
	t_stack_cell	*cell;

	if ((cell = uf_malloc_s(1, sizeof(*cell))) != NULL)
		cell->v_data = data;
	return (cell);
}

bool				f_stack_push(t_stack *v_this, void *data)
{
	t_stack_cell	*push;

	push = D_STACK(create_cell)(data);
	if (push == NULL)
		return (M_ERROR(false, "Bad alloc"));
	push->v_prev = v_this->v_last;
	v_this->v_last = push;
	v_this->v_size = v_this->v_size + 1;
	return (true);
}

void				f_stack_pop(t_stack *v_this)
{
	t_stack_cell	*del;

	if (v_this->v_last == NULL)
		return ;
	del = v_this->v_last;
	v_this->f_destroy(v_this->v_last->v_data);
	v_this->v_last = v_this->v_last->v_prev;
	v_this->v_size = v_this->v_size - 1;
	uf_free_s((void **)&del);
}
