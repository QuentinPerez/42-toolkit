/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_unit_context.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/31 16:10:19 by qperez            #+#    #+#             */
/*   Updated: 2013/12/29 15:54:46 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_unit_context function >
** < add_context >
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

#include <stdlib.h>
#include <unit/s_unit.h>
#include <f_error/m_error.h>
#include <f_string/f_string.h>
#include <unit/s_unit_test.h>
#include <unit/s_unit_context.h>

static void			uf_unit_destroy_test(void *data)
{
	t_unit_test	*test;

	test = (t_unit_test *)data;
	D_LIST(destroy)(&test->v_assert);
	free(data);
}

static t_unit_test	*uf_unit_alloc_test(const char *name,
										void (*test)(t_unit_test *))
{
	t_unit_test	*t;

	t = malloc(sizeof(*t));
	if (t == NULL)
		return ((t_unit_test*)M_ERROR((size_t)NULL, "Bad alloc"));
	t->v_name = name;
	t->f_func = test;
	t->v_failed = false;
	t->v_active = true;
	t->v_tested = false;
	D_LIST(init)(&t->v_assert, free);
	return (t);
}

bool				f_unit_add_context(t_unit *v_this, const char *name,
									   bool (*init)(void *),
									   bool (*destroy)(void *))
{
	t_unit_context	*context;

	context = malloc(sizeof(*context));
	if (context == NULL)
		return (M_ERROR(false, "Bad alloc"));
	context->v_name = name;
	context->f_init = init;
	context->f_destroy = destroy;
	context->v_id = D_LIST(size)(&v_this->v_context) + 1;
	D_LIST(init)(&context->v_test, uf_unit_destroy_test);
	if (D_LIST(push_back)(&v_this->v_context, context) == false)
	{
		free(context);
		return (false);
	}
	return (true);
}

bool				mf_unit_add_test(t_unit *v_this, const char *context,
									 const char *name,
									 void (*test)(t_unit_test *))
{
	t_list_cell	*cell;
	t_unit_test	*t;

	cell = D_LIST(begin)(&v_this->v_context);
	while (cell != NULL)
	{
		if (uf_strcmp(context, ((t_unit_context*)cell->v_data)->v_name) == 0)
			break ;
		cell = cell->v_next;
	}
	if (cell == NULL)
		return (M_ERROR(false, "Could not find %s context", context));
	t = uf_unit_alloc_test(name, test);
	if (t == NULL)
		return (false);
	if (D_LIST(push_back)(&((t_unit_context*)cell->v_data)->v_test, t) == false)
	{
		free(t);
		return (false);
	}
	return (true);
}
