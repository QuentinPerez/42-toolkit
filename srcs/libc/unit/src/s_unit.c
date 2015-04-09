/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_unit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/31 11:09:02 by qperez            #+#    #+#             */
/*   Updated: 2014/12/02 12:03:58 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_unit function>
** < init, destroy >
** Copyright (C) <2013>  Quentin Perez <qperez42@gmail.com>
** This file is part of 42-toolkit.
** 42-toolkit is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <f_secure/f_secure.h>
#include <unit/s_unit.h>
#include <unit/s_unit_context.h>

static void	uf_delete_unit_context(void *data)
{
	t_unit_context	*context;

	context = (t_unit_context*)data;
	D_LIST(destroy)(&context->v_test);
	uf_free_s((void **)&data);
}

bool		f_unit_init(t_unit *v_this)
{
	v_this->v_params.v_run = true;
	v_this->v_params.v_width = 80;
	D_LIST(init)(&v_this->v_context, uf_delete_unit_context);
	return (true);
}

void		f_unit_destroy(t_unit *v_this)
{
	D_LIST(destroy)(&v_this->v_context);
}
