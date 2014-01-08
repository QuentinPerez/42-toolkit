/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vector_modifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/16 15:17:58 by qperez            #+#    #+#             */
/*   Updated: 2014/01/08 18:37:02 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_vector_modifier method>
** < push_back, erase, reserve >
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

static bool			f_vector_realloc(t_vector *v_this, ui size)
{
	void	**tmp;

	tmp = v_this->v_data;
	v_this->v_data = realloc(v_this->v_data, sizeof(*v_this->v_data) * size);
	if (v_this->v_data == NULL)
	{
		v_this->v_data = tmp;
		return (M_ERROR(false, "Bad alloc"));
	}
	v_this->v_capacity = size;
	return (true);
}

static inline void	f_vector_decal(t_vector *v_this, ui start)
{
	ui	end;

	end = v_this->v_size - 1;
	while (start < end)
	{
		v_this->v_data[start] = v_this->v_data[start + 1];
		v_this->v_data[start + 1] = NULL;
		start = start + 1;
	}
}

bool				f_vector_push_back(t_vector *v_this, void *data)
{
	ui	new_size;

	if (data == NULL)
		M_INFOS(false, "Null pointer");
	new_size = v_this->f_realloc(v_this->v_size);
	if (v_this->v_size + 1 > v_this->v_capacity
		&& D_VECTOR(realloc)(v_this, new_size) == false)
		return (false);
	v_this->v_data[v_this->v_size] = data;
	v_this->v_size = v_this->v_size + 1;
	return (true);
}

void				*f_vector_erase(t_vector *v_this, void *erase)
{
	ui		i;
	void	*ret;

	i = 0;
	while (i < v_this->v_size)
	{
		if (v_this->v_data[i] == erase)
			break ;
		i = i + 1;
	}
	if (i == v_this->v_size || v_this->v_data[i] == NULL)
		return (NULL);
	ret = v_this->v_data[i];
	v_this->v_data[i] = NULL;
	D_VECTOR(decal)(v_this, i);
	v_this->v_size = v_this->v_size - 1;
	return (ret);
}

bool				f_vector_reserve(t_vector *v_this, ui size)
{
	if (size <= v_this->v_capacity)
		return (false);
	return (D_VECTOR(realloc)(v_this, size));
}
