/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_array_modifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/02 15:23:05 by qperez            #+#    #+#             */
/*   Updated: 2014/01/08 18:01:18 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_array_modifier function>
** < push_back, delete_if, resize >
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
#include <array/s_array.h>
#include <f_error/m_error.h>
#include <f_memory/f_memory.h>

static bool	f_array_realloc(t_array *v_this, ui size)
{
	void	*tmp;

	tmp = v_this->v_data;
	v_this->v_data = realloc(v_this->v_data, size * v_this->v_type_size);
	if (v_this->v_data == NULL)
	{
		v_this->v_data = tmp;
		return (M_ERROR(false, "Bad alloc"));
	}
	v_this->v_capacity = size;
	return (true);
}

bool		f_array_resize(t_array *v_this, ui size)
{
	if (size < v_this->v_capacity)
		return (M_ERROR(false, "Size %d is lower than capacity", size));
	return (D_ARRAY(realloc)(v_this, size));
}

bool		f_array_push_back(t_array *v_this, void *data)
{
	char	*to;
	ui		new_size;

	new_size = v_this->f_realloc(v_this->v_capacity);
	if (v_this->v_size + 1 > v_this->v_capacity
		&& D_ARRAY(realloc)(v_this, new_size) == false)
		return (false);
	to = (char *)v_this->v_data;
	to = to + v_this->v_size * v_this->v_type_size;
	uf_memcpy(to, data, v_this->v_type_size);
	v_this->v_size = v_this->v_size + 1;
	return (true);
}

void		f_array_delete_if(t_array *v_this,
							bool (*ft_cmp)(void *d1, void *d2), void *data)
{
	ui		i;
	ui		size;
	char	*ptr;

	i = 0;
	ptr = (char *)v_this->v_data;
	size = v_this->v_size * v_this->v_type_size;
	while (i < size)
	{
		if (ft_cmp((void *)(ptr + i), data) == true)
		{
			uf_memcpy(ptr + i, ptr + i + v_this->v_type_size,
					size - i - v_this->v_type_size);
			uf_memset(ptr + size - v_this->v_type_size, 0, v_this->v_type_size);
			v_this->v_size = v_this->v_size - 1;
			size = v_this->v_size * v_this->v_type_size;
		}
		else
			i = i + v_this->v_type_size;
	}
}
