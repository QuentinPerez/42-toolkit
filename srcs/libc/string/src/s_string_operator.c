/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/28 13:28:29 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:52:19 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_string_operator function>
** < erase, insert >
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
#include <f_string/f_str_tools.h>

void	f_string_erase(t_string *v_this, size_t from, size_t to)
{
	size_t	size;

	if (from >= to || to >= v_this->v_size)
		return ;
	size = v_this->v_size - to;
	uf_memcpy(v_this->v_str + from, v_this->v_str + to, size);
	uf_memset(v_this->v_str + from + size, '\0', to - from);
	v_this->v_size = v_this->v_size - (to - from);
}

bool	f_string_insert(t_string *v_this, const char *insert, size_t at)
{
	size_t	size;

	if (at >= v_this->v_size)
		return (D_STRING(add_str)(v_this, insert));
	size = uf_str_len(insert);
	if (size == 0)
		return (true);
	if (v_this->v_size + size + 1 > v_this->v_capacity
		&& uf_string_realloc(v_this, size + 1) == false)
		return (false);
	uf_memcpy(v_this->v_str + at + size, v_this->v_str + at,
			v_this->v_size - at);
	uf_memcpy(v_this->v_str + at, insert, size);
	v_this->v_size = v_this->v_size + size;
	return (true);
}
