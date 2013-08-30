/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/29 17:30:08 by qperez            #+#    #+#             */
/*   Updated: 2013/08/30 15:57:53 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains all f_print function>
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

#include <f_print_fd.h>

ssize_t	uf_print_char(char c)
{
	return (uf_print_char_fd(c, 1));
}

ssize_t	uf_print_str(const char *str)
{
	return (uf_print_str_fd(str, 1));
}

void	uf_print_nbr(ssize_t nbr)
{
	uf_print_nbr_fd(nbr, 1);
}

void	uf_print_nbr_base(ssize_t nbr, ssize_t base)
{
	uf_print_nbr_base_fd(nbr, 1, base);
}

void	uf_print_addr(void *addr)
{
	uf_print_addr_fd(addr, fd);
}
