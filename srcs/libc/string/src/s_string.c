/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/22 12:13:42 by qperez            #+#    #+#             */
/*   Updated: 2014/10/13 15:30:46 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_string function>
** < init, clear, destroy >
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
#include <stdint.h>
#include <string/s_string.h>
#include <f_error/m_error.h>
#include <f_memory/f_memory.h>

static inline size_t	uf_string_realloc(size_t size)
{
	return (size << 1);
}

bool				f_string_init(t_string *v_this,
								size_t (*uf_realloc)(size_t size))
{
	size_t	size;

	size = 2;
	v_this->v_size = 0;
	if (size > SIZE_MAX / sizeof(*v_this->v_str)
		|| (v_this->v_str = malloc(size * sizeof(*v_this->v_str))) == NULL)
	if (v_this->v_str == NULL)
		return (M_ERROR(false, "Bad alloc"));
	uf_memset(v_this->v_str, 0, size * sizeof(*v_this->v_str));
	v_this->f_realloc = uf_string_realloc;
	if (uf_realloc != NULL)
		v_this->f_realloc = uf_realloc;
	v_this->v_capacity = size;
	v_this->v_hex = "0123456789ABCDEF";
	return (true);
}

void				f_string_clear(t_string *v_this)
{
	size_t	size;

	size = v_this->v_capacity;
	while (size > 0)
	{
		v_this->v_str[size - 1] = '\0';
		size = size - 1;
	}
	v_this->v_size = 0;
}

void				f_string_destroy(t_string *v_this)
{
	free(v_this->v_str);
	uf_memset(v_this, 0, sizeof(*v_this));
}
