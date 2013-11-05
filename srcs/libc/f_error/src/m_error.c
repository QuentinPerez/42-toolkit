/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 12:30:46 by qperez            #+#    #+#             */
/*   Updated: 2013/11/05 23:59:37 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains m_error function>
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

#include <f_string/f_print_fd.h>
#include <string/s_string.h>

char	mf_print_infos(const char *file, int line, const char *fct)
{
#ifdef	D_ERRORS_ON
	uf_print_str_fd("\033[0;37m", 2);
	uf_print_str_fd(file, 2);
	uf_print_str_fd(", line \033[1;33m", 2);
	uf_print_nbr_fd(line, 2);
	uf_print_str_fd(": \033[1;37m", 2);
	uf_print_str_fd(fct, 2);
	uf_print_str_fd("()\n\033[1;31m→\t", 2);
#endif
	(void)file;
	(void)line;
	(void)fct;
	return (0);
}

size_t	mf_error(char nothing, size_t ret, const char *fmt, ...)
{
#ifdef	D_ERRORS_ON
	va_list		ap;
	t_string	str;

	if (fmt == NULL)
	{
		uf_print_str_fd("An internal has occured\n", 2);
		return (ret);
	}
	va_start(ap, fmt);
	D_STRING(init)(&str, 0);
	D_STRING(variadic_list)(&str, fmt, &ap);
	D_STRING(add_str)(&str, ".\033[0;37m\n");
	D_STRING(print_fd)(&str, 2);
	D_STRING(destroy)(&str);
	va_end(ap);
#endif
	(void)nothing;
	(void)fmt;
	return (ret);
}

void	mf_error_v(char nothing, const char *fmt, ...)
{
#ifdef	D_ERRORS_ON
	mf_error(0, 0, fmt);
#endif
	(void)nothing;
	(void)fmt;
}

void	mf_infos(const char *funct, const char *infos, ...)
{
#ifdef	D_ERRORS_ON
	va_list		ap;
	t_string	str;

	if (infos == NULL)
	{
		uf_print_str_fd("An internal has occured\n", 2);
		return ;
	}
	va_start(ap, infos);
	D_STRING(init)(&str, 0);
	D_STRING(variadic)(&str, "\033[1;37m→\t%s(): \033[0;33m", funct);
	D_STRING(variadic_list)(&str, infos, &ap);
	D_STRING(add_str)(&str, ".\033[0m\n");
	D_STRING(print_fd)(&str, 2);
	D_STRING(destroy)(&str);
	va_end(ap);
#endif
	(void)funct;
	(void)infos;
}
