/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string_add_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/25 13:16:21 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:51:22 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_string_add_number function>
** < add_nbr_base, add_nbr, add_ptr >
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

#include <string/s_string.h>

size_t		uf_string_realloc(t_string *v_this, size_t add);

static size_t	uf_string_get_digit(ssize_t nbr, size_t base, size_t *alloc)
{
	size_t	digit;

	digit = 1;
	*alloc = 1;
	if (nbr < 0)
	{
		*alloc = *alloc + 1;
		nbr = -nbr;
	}
	while ((nbr / digit) >= base)
	{
		digit = digit * base;
		*alloc = *alloc + 1;
	}
	*alloc = *alloc + 1;
	return (digit);
}


bool		f_string_add_nbr_base(t_string *v_this, ssize_t nbr, size_t base)
{
	size_t	size;
	size_t	digit;

	digit = uf_string_get_digit(nbr, base, &size);
	if (base == 16 && D_STRING(add_str)(v_this, "0x") == false)
		return (false);
	if (v_this->v_size + size > v_this->v_capacity
		&& uf_string_realloc(v_this, size) == false)
		return (false);
	if (nbr < 0)
	{
		v_this->v_str[v_this->v_size] = '-';
		v_this->v_size = v_this->v_size + 1;
		nbr = -nbr;
	}
	while (digit > 0)
	{
		v_this->v_str[v_this->v_size] = v_this->v_hex[nbr / digit % base];
		v_this->v_size = v_this->v_size + 1;
		digit = digit / base;
	}
	v_this->v_str[v_this->v_size] = '\0';
	return (true);
}

bool		f_string_add_nbr(t_string *v_this, ssize_t nbr)
{
	return (D_STRING(add_nbr_base)(v_this, nbr, 10));
}

bool		f_string_add_ptr(t_string *v_this, void *addr)
{
	size_t		nbr;
	size_t		digit;
	size_t		size;

	size = 1;
	digit = 1;
	nbr = (size_t)addr;
	while ((nbr / digit) >= 16)
	{
		digit = digit * 16;
		size = size + 1;
	}
	size = size + 1;
	if (v_this->v_size + size + 2 > v_this->v_capacity
		&& uf_string_realloc(v_this, size) == false)
		return (false);
	D_STRING(add_str)(v_this, "0x");
	while (digit > 0)
	{
		v_this->v_str[v_this->v_size] = v_this->v_hex[nbr / digit % 16];
		v_this->v_size = v_this->v_size + 1;
		digit = digit / 16;
	}
	v_this->v_str[v_this->v_size] = '\0';
	return (true);
}
