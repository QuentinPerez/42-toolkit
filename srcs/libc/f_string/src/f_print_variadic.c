/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_variadic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/30 11:05:34 by qperez            #+#    #+#             */
/*   Updated: 2013/10/30 11:30:38 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains all f_print_variadic function>
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
#include <stdarg.h>

static void	uf_print_treat_argument(va_list *ap, const char **fmt, ui fd)
{
	*fmt = *fmt + 1;
	if (**fmt == 'd' || **fmt == 'i')
		uf_print_nbr_fd(va_arg(*ap, ssize_t), fd);
	else if (**fmt == 'x' || **fmt == 'X')
		uf_print_nbr_base_fd(va_arg(*ap, ssize_t), 16, fd);
	else if (**fmt == 'c')
		uf_print_char_fd(va_arg(*ap, int), fd);
	else if (**fmt == 's')
		uf_print_str_fd(va_arg(*ap, char *), fd);
	else if (**fmt == 'p')
		uf_print_addr_fd(va_arg(*ap, void *), fd);
}

void		uf_print_variadic_fd(ui fd, const char *fmt, ...)
{
	va_list		ap;
	const char	*tmp;

	tmp = fmt;
	va_start(ap, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			uf_print_nstr_fd(tmp, fmt - tmp, fd);
			uf_print_treat_argument(&ap, &fmt, fd);
			fmt = fmt + 1;
			tmp = fmt;
		}
		else
			fmt = fmt + 1;
	}
	if (tmp != fmt)
			uf_print_nstr_fd(tmp, fmt - tmp, fd);
	va_end(ap);
}

void		uf_print_variadic(const char *fmt, ...)
{
	va_list		ap;
	const char	*tmp;

	tmp = fmt;
	va_start(ap, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			uf_print_nstr_fd(tmp, fmt - tmp, 1);
			uf_print_treat_argument(&ap, &fmt , 1);
			fmt = fmt + 1;
			tmp = fmt;
		}
		else
			fmt = fmt + 1;
	}
	if (tmp != fmt)
			uf_print_nstr_fd(tmp, fmt - tmp, 1);
	va_end(ap);
}
