/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/16 12:10:46 by qperez            #+#    #+#             */
/*   Updated: 2013/12/29 15:55:06 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_vector method>
** < init, destroy, clear >
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

#include <vector/s_vector.h>
#include <stdlib.h>
#include <f_error/m_error.h>
#include <f_memory/f_memory.h>

static inline void	uf_vector_delete(void *ptr)
{
	(void)ptr;
}

static inline ui	uf_vector_realloc(ui size)
{
	return (size << 1);
}

bool				f_vector_init(t_vector *v_this,
								  ui (*uf_realloc)(ui size),
								  void (*uf_delete)(void *ptr))
{
	v_this->v_size = 0;
	v_this->v_capacity = 0;
	v_this->f_realloc = uf_realloc;
	if (uf_realloc == NULL)
		v_this->f_realloc = uf_vector_realloc;
	v_this->f_delete = uf_delete;
	if (uf_delete == NULL)
		v_this->f_delete = uf_vector_delete;
	v_this->v_data = calloc(2, sizeof(*v_this->v_data));
	if (v_this->v_data == NULL)
		return (M_ERROR(false, "Bad alloc"));
	v_this->v_capacity = 2;
	return (true);
}

inline void			f_vector_clear(t_vector *v_this)
{
	int	size;

	size = (int)v_this->v_size - 1;
	while (size > -1)
	{
		v_this->f_delete(v_this->v_data[size]);
		size = size - 1;
	}
	v_this->v_size = 0;
}

void				f_vector_destroy(t_vector *v_this)
{
	D_VECTOR(clear)(v_this);
	if (v_this->v_capacity > 0)
		free(v_this->v_data);
	uf_memset(v_this, 0, sizeof(*v_this));
}
