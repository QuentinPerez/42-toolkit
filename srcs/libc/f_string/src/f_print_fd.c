/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 15:06:45 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:38:02 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains f_print_fd function>
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
#include <f_string/f_str_tools.h>

ssize_t	uf_print_char_fd(char c, t_ui fd)
{
	return (write(fd, &c, 1));
}

ssize_t	uf_print_str_fd(const char *str, t_ui fd)
{
	return (write(fd, str, uf_str_len(str)));
}

void	uf_print_nbr_base_fd(ssize_t nbr, ssize_t base, t_ui fd)
{
	ssize_t	digit;

	digit = 1;
	while ((nbr / digit) >= base || (nbr / digit) <= -base)
		digit = digit * base;
	if (nbr < 0)
	{
		uf_print_char_fd('-', fd);
		nbr = -nbr;
	}
	while (digit > 0)
	{
		uf_print_in_base(nbr / digit % base, fd);
		digit = digit / base;
	}
}

void	uf_print_nbr_fd(ssize_t nbr, t_ui fd)
{
	uf_print_nbr_base_fd(nbr, 10, fd);
}

void	uf_print_addr_fd(void *addr, t_ui fd)
{
	size_t	nbr;
	size_t	digit;

	digit = 1;
	nbr = (size_t)addr;
	while ((nbr / digit) >= 16)
		digit = digit * 16;
	uf_print_str_fd("0x", fd);
	while (digit > 0)
	{
		uf_print_in_base(nbr / digit % 16, fd);
		digit = digit / 16;
	}
}
