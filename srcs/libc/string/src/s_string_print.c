/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/25 11:05:31 by qperez            #+#    #+#             */
/*   Updated: 2013/10/25 11:19:48 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_string_print function>
** < print_memory, print_fd, print >
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
#include <f_string/f_print_fd.h>
#include <f_memory/f_memory.h>

void	f_string_print_memory(t_string *v_this, const char *name)
{
	if (name != NULL)
		m_infos(name);
	else
		m_infos("string");
	uf_print_memory(v_this->v_str, v_this->v_capacity);
}

void	f_string_print_fd(t_string *v_this, ui fd)
{
	write(fd, v_this->v_str, v_this->v_size);
}

void	f_string_print(t_string *v_this)
{
	f_string_print_fd(v_this, 1);
}
