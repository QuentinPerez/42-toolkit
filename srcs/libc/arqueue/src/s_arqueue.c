/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_arqueue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/30 00:38:02 by qperez            #+#    #+#             */
/*   Updated: 2014/06/30 00:38:16 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_arqueue function>
** < init, destroy >
** Copyright (C) <2014>  Quentin Perez <qperez42@gmail.com>
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

#include <arqueue/s_arqueue.h>
#include <f_error/m_error.h>
#include <f_memory/f_memory.h>
#include <stdlib.h>

bool		f_arqueue_init(t_arqueue *v_this, size_t elem_size, size_t nb_elem)
{
	v_this->v_start = 0;
	v_this->v_end = 0;
	v_this->v_size = 0;
	if ((v_this->v_array = malloc(elem_size * nb_elem)) == NULL)
		return (M_ERROR(false, "Bad alloc"));
	v_this->v_capacity = nb_elem;
	v_this->v_sizeof = elem_size;
	return (true);
}

bool		f_arqueue_push(t_arqueue *v_this, void *push)
{
	if (v_this->v_size >= v_this->v_capacity)
		return (M_ERROR(false, "Couldn't push element"));
	uf_memcpy(&v_this->v_array[v_this->v_end * v_this->v_sizeof], push,
															v_this->v_sizeof);
	v_this->v_end = v_this->v_end + 1;
	if (v_this->v_end >= v_this->v_capacity)
		v_this->v_end = 0;
	v_this->v_size = v_this->v_size + 1;
	return (true);
}

bool		f_arqueue_empty(t_arqueue *v_this)
{
	return (v_this->v_size == 0);
}

void		*f_arqueue_pop(t_arqueue *v_this)
{
	void	*ret;

	if (v_this->v_size == 0)
		return (NULL);
	v_this->v_size = v_this->v_size - 1;
	ret = &v_this->v_array[v_this->v_start * v_this->v_sizeof];
	v_this->v_start = v_this->v_start + 1;
	if (v_this->v_start >= v_this->v_capacity)
		v_this->v_start = 0;
	return (ret);
}

void		f_arqueue_destroy(t_arqueue *v_this)
{
	free(v_this->v_array);
}
