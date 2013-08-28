/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 12:30:46 by qperez            #+#    #+#             */
/*   Updated: 2013/08/28 16:28:05 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This function contains all error function>
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

#include <m_error.h>
#include <f_print_fd.h>

char	fm_print_infos(const char *file, int line, const char *fct)
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

size_t	fm_error(char nothing, const char *err, size_t ret)
{
#ifdef	D_ERRORS_ON
	uf_print_str_fd(err, 2);
	uf_print_str_fd(".\033[0;37m\n", 2);
#endif
	(void)nothing;
	(void)err;
	return (ret);
}

void	fm_error_v(char nothing, const char *err)
{
#ifdef	D_ERRORS_ON
	fm_error(0, err, 0);
#endif
	(void)nothing;
	(void)err;
}

void	fm_error_infos(const char *funct, const char *infos)
{
#ifdef	D_ERRORS_ON
	uf_print_str_fd("\033[1;37m→\t", 1);
	uf_print_str_fd(funct, 1);
	uf_print_str_fd("(): \033[0;33m", 1);
	uf_print_str_fd(infos, 1);
	uf_print_str_fd(".\033[0;37m\n", 1);
#endif
	(void)funct;
	(void)infos;
}
