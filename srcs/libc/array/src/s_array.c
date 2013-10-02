/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_array.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/02 12:59:24 by qperez            #+#    #+#             */
/*   Updated: 2013/10/02 13:31:42 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_array function>
** < init, destroy >
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

#include <s_array.h>
#include <m_error.h>
#include <stdlib.h>
#include <f_memory.h>

static inline void	uf_array_delete(void *ptr)
{
	(void)ptr;
}

static inline ui	uf_array_realloc(ui size)
{
	return (size << 1);
}

bool				f_array_init(t_array *v_this,
								 ui (*uf_realloc)(ui size),
								 void (*uf_delete)(void *ptr),
								 ui type_size)
{
	v_this->v_size = 0;
	v_this->v_capacity = 0;
	v_this->f_realloc = uf_realloc;
	if (uf_realloc == NULL)
		v_this->f_realloc = uf_array_realloc;
	v_this->f_delete = uf_delete;
	if (uf_delete == NULL)
		v_this->f_delete = uf_array_delete;
	v_this->v_data = calloc(2, type_size);
	if (v_this->v_data == NULL)
		return (m_error("Bad alloc", false));
	v_this->v_capacity = 2;
	return (true);
}

void				f_array_destroy(t_array *v_this)
{
	free(v_this->v_data);
	uf_memset(v_this, 0, sizeof(*v_this));
}
