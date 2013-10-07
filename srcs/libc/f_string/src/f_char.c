/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/07 20:56:15 by qperez            #+#    #+#             */
/*   Updated: 2013/10/07 21:13:01 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains function>
** < uf_tolower, uf_toupper, uf_is_lower, uf_is_upper >
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
#include <d_bool.h>

bool	uf_is_upper(const uc c)
{
	return (c > '@' && c < '[');
}

bool	uf_is_lower(const uc c)
{
	return (c > '`' && c < '{');
}

uc		uf_to_lower(const uc c)
{
	if (uf_is_upper(c) == true)
		return (c + 32);
	return (c);
}

uc		uf_to_upper(const uc c)
{
	if (uf_is_lower(c) == true)
		return (c - 32);
	return (c);
}
