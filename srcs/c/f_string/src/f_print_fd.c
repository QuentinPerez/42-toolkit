/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 15:06:45 by qperez            #+#    #+#             */
/*   Updated: 2013/08/29 14:10:05 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains all f_string function>
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
#include <f_str_tools.h>

ssize_t	uf_print_char_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

ssize_t	uf_print_str_fd(const char *str, int fd)
{
	return (write(fd, str, uf_str_len(str)));
}

void	uf_print_nbr_fd(ssize_t nbr, int fd)
{
	ssize_t	digit;

	digit = 1;
	while ((nbr / digit) >= 10 || (nbr / digit) <= -10)
		digit = digit * 10;
	if (nbr < 0)
		uf_print_char_fd('-', fd);
	while (digit > 0)
	{
		if (nbr < 0)
			uf_print_char_fd(nbr / digit % 10 * - 1 + '0', fd);
		else
			uf_print_char_fd(nbr / digit % 10 + '0', fd);
		digit = digit / 10;
	}
}
