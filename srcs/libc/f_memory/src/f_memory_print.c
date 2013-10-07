/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_memory_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/08 00:22:04 by qperez            #+#    #+#             */
/*   Updated: 2013/10/08 01:11:06 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains all f_memory_print function>
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

#include <t_types.h>
#include <f_print.h>

static void	uf_print_content(uc *data, ui size)
{
	ui	i;

	i = 0;
	uf_print_char(' ');
	while (i < size)
	{
		if (data[i] < 32 || data[i] == 127)
			uf_print_char('.');
		else
			uf_print_char(data[i]);
		i = i + 1;
	}
	uf_print_char('\n');
}

static void	uf_print_hex(char c)
{
	if (c < 16)
		uf_print_char('0');
	uf_print_nbr_base(c, 16);
}

static uc	*uf_print_data(uc *data, ui size)
{
	ui	i;

	i = 0;
	uf_print_addr(data);
	uf_print_str(": ");
	while (i < size)
	{
		if (i % 2 == 0 && i != 0)
			uf_print_char(' ');
		uf_print_hex(*data);
		data = data + 1;
		i = i + 1;
	}
	while (i < 16)
	{
		if (i % 2 == 0 && i != 0)
			uf_print_char(' ');
		uf_print_str("  ");
		i = i + 1;
	}
	uf_print_content(data - size, size);
	return (data);
}

void		*uf_print_memory(const void *addr, ui size)
{
	uc	*data;

	data = (uc*)addr;
	while (size > 16)
	{
		data = uf_print_data(data, 16);
		size = size - 16;
	}
	data = uf_print_data(data, size);
	return ((void*)addr);
}
