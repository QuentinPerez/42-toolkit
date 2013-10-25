/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/25 13:16:21 by qperez            #+#    #+#             */
/*   Updated: 2013/10/25 14:37:32 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_string_add function>
** < add_str >
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

#include <string/s_string.h>
#include <f_error/m_error.h>
#include <f_string/f_str_tools.h>
#include <f_string/f_string.h>
#include <f_memory/f_memory.h>
#include <stdlib.h>

bool	uf_string_realloc(t_string *v_this, ui add)
{
	char	*tmp;
	ui		new_capacity;

	new_capacity = v_this->v_capacity;
	while (v_this->v_size + add > new_capacity)
		new_capacity = v_this->f_realloc(new_capacity);
	tmp = realloc(v_this->v_str, new_capacity);
	if (v_this->v_str == NULL)
	{
		free(v_this->v_str);
		uf_memset(v_this, 0, sizeof(*v_this));
		return (m_error("Bad alloc", false));
	}
	v_this->v_str = tmp;
	v_this->v_capacity = new_capacity;
	return (true);
}

bool	f_string_add_str(t_string *v_this, const char *str)
{
	ui	size;

	size = uf_str_len(str);
	if (size == 0)
		return (m_error("Your string is empty", false));
	size = size + 1;
	if (v_this->v_size + size > v_this->v_capacity &&
		uf_string_realloc(v_this, size) == false)
		return (false);
	uf_strcat(v_this->v_str + v_this->v_size, str);
	v_this->v_size = v_this->v_size + size - 1;
	return (true);
}


