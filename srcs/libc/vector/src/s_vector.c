/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/16 12:10:46 by qperez            #+#    #+#             */
/*   Updated: 2014/12/02 12:00:54 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_vector method>
** < init, destroy, clear >
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

#include <vector/s_vector.h>
#include <f_secure/f_secure.h>
#include <f_error/m_error.h>
#include <f_memory/f_memory.h>

static inline void		uf_vector_delete(void *ptr)
{
	(void)ptr;
}

static inline size_t	uf_vector_realloc(size_t size)
{
	return (size << 1);
}

bool					f_vector_init(t_vector *v_this,
									size_t (*uf_realloc)(size_t size),
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
	if ((v_this->v_data = uf_malloc_s(2, sizeof(*v_this->v_data))) == NULL)
		return (M_ERROR(false, "Bad alloc"));
	uf_memset(v_this->v_data, 0, 2 * sizeof(*v_this->v_data));
	v_this->v_capacity = 2;
	return (true);
}

inline void				f_vector_clear(t_vector *v_this)
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

void					f_vector_destroy(t_vector *v_this)
{
	D_VECTOR(clear)(v_this);
	if (v_this->v_capacity > 0)
		uf_free_s((void **)&v_this->v_data);
	v_this->v_size = 0;
	v_this->v_capacity = 0;
	v_this->f_realloc = NULL;
	v_this->f_delete = NULL;
}
