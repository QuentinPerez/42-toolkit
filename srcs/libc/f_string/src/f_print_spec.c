/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/25 15:16:37 by qperez            #+#    #+#             */
/*   Updated: 2015/07/03 17:16:08 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains all f_print_spect  function>
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

#include <f_string/f_print_fd.h>
#include <f_string/f_print.h>

void	uf_print_floating_nbr_fd(double nbr, size_t digit, int fd)
{
	uf_print_nbr_fd((ssize_t)nbr, fd);
	uf_print_char_fd('.', fd);
	while (digit > 0)
	{
		nbr = nbr - (double)(ssize_t)nbr;
		nbr = nbr * 10;
		uf_print_char_fd((char)((ssize_t)nbr + '0'), fd);
		digit = digit - 1;
	}
}

void	uf_print_floating_nbr(double nbr, size_t digit)
{
	uf_print_floating_nbr_fd(nbr, digit, 1);
}

void	uf_print_bits_fd(size_t value, size_t size, int fd)
{
	size_t	max;

	max = ((size_t)1 << (size * 8 - 1));
	while (max > 0)
	{
		if (value & max)
			uf_print_nbr_fd(1, fd);
		else
			uf_print_nbr_fd(0, fd);
		max = max >> 1;
	}
}

void	uf_print_bits(size_t value, size_t size)
{
	uf_print_bits_fd(value, size, 1);
}
