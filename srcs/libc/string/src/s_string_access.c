/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/25 11:29:57 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:50:49 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_string_access function>
** < size, capacity, empty, dup >
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
#include <f_string/f_string.h>

inline t_ui	f_string_size(const t_string *v_this)
{
	return (v_this->v_size);
}

inline t_ui	f_string_capacity(const t_string *v_this)
{
	return (v_this->v_capacity);
}

inline bool	f_string_empty(const t_string *v_this)
{
	return (v_this->v_size == 0);
}

char		*f_string_dup(const t_string *v_this)
{
	return (uf_strdup(v_this->v_str));
}

const char	*f_string_str(const t_string *v_this)
{
	return (v_this->v_str);
}
