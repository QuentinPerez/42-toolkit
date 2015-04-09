/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string_resize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/25 18:38:40 by qperez            #+#    #+#             */
/*   Updated: 2014/12/02 11:58:44 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_string_resize function>
** <  >
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

#include <string/s_string.h>
#include <f_memory/f_memory.h>
#include <f_error/m_error.h>
#include <f_secure/f_secure.h>

bool	uf_string_realloc(t_string *v_this, size_t add)
{
	char	*tmp;
	size_t	new_capacity;

	new_capacity = v_this->v_capacity;
	while (v_this->v_size + add > new_capacity)
		new_capacity = v_this->f_realloc(new_capacity);
	if ((tmp = uf_realloc_s(v_this->v_str, 1, new_capacity)) == NULL)
	{
		uf_free_s((void **)&v_this->v_str);
		uf_memset(v_this, 0, sizeof(*v_this));
		return (M_ERROR(false, "Bad alloc"));
	}
	v_this->v_str = tmp;
	uf_memset(v_this->v_str + v_this->v_capacity, '\0',
			new_capacity - v_this->v_capacity);
	v_this->v_capacity = new_capacity;
	return (true);
}
