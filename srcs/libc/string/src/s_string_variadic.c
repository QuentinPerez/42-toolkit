/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string_variadic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/25 19:19:43 by qperez            #+#    #+#             */
/*   Updated: 2013/11/04 10:06:29 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_string_variadic function>
** < variadic >
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
#include <stdarg.h>

static bool	uf_string_treat_argument_next(t_string *v_this, va_list *ap,
										  const char **fmt)
{
	if (**fmt == 's')
	{
		if (D_STRING(add_str)(v_this, va_arg(*ap, char *)) == false)
			return (false);
	}
	else if (**fmt == 'p')
	{
		if (D_STRING(add_ptr)(v_this, va_arg(*ap, void *)) == false)
			return (false);
	}
	return (true);
}

static bool	uf_string_treat_argument(t_string *v_this, va_list *ap,
									 const char **fmt)
{
	*fmt = *fmt + 1;
	if (**fmt == 'd' || **fmt == 'i')
	{
		if (D_STRING(add_nbr)(v_this, va_arg(*ap, ssize_t)) == false)
			return (false);
	}
	else if (**fmt == 'x' || **fmt == 'X')
	{
		if (D_STRING(add_nbr_base)(v_this, va_arg(*ap, ssize_t), 16) == false)
			return (false);
	}
	else if (**fmt == 'c')
	{
		if (D_STRING(add_char)(v_this, va_arg(*ap, int)) == false)
			return (false);
	}
	else
		return (uf_string_treat_argument_next(v_this, ap, fmt));
	return (true);
}

bool		f_string_variadic(t_string *v_this, const char *fmt, ...)
{
	va_list		ap;
	const char	*tmp;
	bool		error;

	tmp = fmt;
	error = false;
	va_start(ap, fmt);
	while (*fmt != '\0' && error == false)
	{
		if (*fmt == '%')
		{
			if (D_STRING(add_nstr)(v_this, tmp, fmt - tmp) == false ||
				uf_string_treat_argument(v_this, &ap, &fmt) == false)
				error = true;
			fmt = fmt + 1;
			tmp = fmt;
		}
		else
			fmt = fmt + 1;
	}
	if (error == false && tmp != fmt &&
		D_STRING(add_nstr)(v_this, tmp, fmt - tmp) == false)
		error = true;
	va_end(ap);
	return (error);
}

bool		f_string_variadic_list(t_string *v_this, const char *fmt,
								   va_list *ap)
{
	const char	*tmp;
	bool		error;

	tmp = fmt;
	error = false;
	while (*fmt != '\0' && error == false)
	{
		if (*fmt == '%')
		{
			if (D_STRING(add_nstr)(v_this, tmp, fmt - tmp) == false ||
				uf_string_treat_argument(v_this, ap, &fmt) == false)
				error = true;
			fmt = fmt + 1;
			tmp = fmt;
		}
		else
			fmt = fmt + 1;
	}
	if (error == false && tmp != fmt &&
		D_STRING(add_nstr)(v_this, tmp, fmt - tmp) == false)
		error = true;
	return (error);
}
