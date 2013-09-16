/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/16 12:10:46 by qperez            #+#    #+#             */
/*   Updated: 2013/09/16 12:52:28 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This function contains s_vector method>
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

#include <s_vector.h>
#include <stdlib.h>
#include <m_error.h>

static inline void	uf_vector_delete(void *ptr)
{
	(void)ptr;
}

static inline uint	uf_vector_realloc(uint size)
{
	return (size << 1);
}

bool				f_vector_init(t_vector *v_this,
								  uint (*uf_realloc)(uint size),
								  void (*uf_delete)(void *ptr))
{
	v_this->v_size = 0;
	v_this->v_capacity = 0;
	v_this->f_realloc = uf_realloc;
	if (uf_realloc == NULL)
		v_this->f_realloc = &uf_vector_realloc;
	v_this->f_delete = uf_delete;
	if (uf_delete == NULL)
		v_this->f_delete = &uf_vector_delete;
	v_this->v_data = malloc(sizeof(*v_this->v_data) * 2);
	if (v_this->v_data == NULL)
		return (m_error("Bad alloc", false));
	v_this->v_capacity = 2;
	return (true);
}

void	f_vector_destroy(t_vector *v_this)
{
	uint	i;

	i = 0;
	while (i < v_this->v_size)
	{
		v_this->f_delete(v_this->v_data[i]);
		free(v_this->v_data[i]);
		i = i + 1;
	}
	free(v_this->v_data);
}
