/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/07 20:56:15 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:31:40 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains function>
** < uf_tolower, uf_toupper, uf_is_lower, uf_is_upper >
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

#include <stdbool.h>

bool			uf_is_upper(const unsigned char c)
{
	return (c > '@' && c < '[');
}

bool			uf_is_lower(const unsigned char c)
{
	return (c > '`' && c < '{');
}

unsigned char	uf_to_lower(const unsigned char c)
{
	if (uf_is_upper(c) == true)
		return (c + 32);
	return (c);
}

unsigned char	uf_to_upper(const unsigned char c)
{
	if (uf_is_lower(c) == true)
		return (c - 32);
	return (c);
}
