/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/13 12:48:51 by qperez            #+#    #+#             */
/*   Updated: 2013/11/03 23:42:21 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains error method>
** < init, destroy, add, add_v >
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

#include <fcntl.h>
#include <stdarg.h>
#include <error/s_error.h>
#include <string/s_string.h>

bool	f_error_init(t_error *v_this, const char *filename)
{
	if (filename == NULL)
	{
		v_this->v_fd = 2;
		return (true);
	}
	v_this->v_fd = open(filename, O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 0644);
	return (v_this->v_fd != -1);
}

bool	mf_add(t_error *v_this, char nothing, bool ret, const char *error, ...)
{
	va_list		ap;
	t_string	str;

	va_start(ap, error);
	D_STRING(init)(&str, 0);
	D_STRING(add_str)(&str, "()\n\t\t-> ");
	D_STRING(variadic_list)(&str, error, &ap);
	D_STRING(add_char)(&str, '\n');
	D_STRING(print_fd)(&str, v_this->v_fd);
	D_STRING(destroy)(&str);
	va_end(ap);
	(void)nothing;
	return (ret);
}

void	f_error_destroy(t_error *v_this)
{
	if (v_this->v_fd > 2)
		close(v_this->v_fd);
}
