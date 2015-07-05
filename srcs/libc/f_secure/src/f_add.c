/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/07 19:56:56 by qperez            #+#    #+#             */
/*   Updated: 2015/07/03 16:23:43 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains uf_*add functions>
** Copyright (C) <2014>  Quentin Perez <qperez42@gmail.com>
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
#include <limits.h>
#include <f_error/m_error.h>
#include <f_secure/f_secure.h>

bool	uf_hhu_add(unsigned char a, unsigned char b, unsigned char *sum)
{
	if (UCHAR_MAX - a < b)
		return (M_ERROR(false, "Unsigned char overflow"));
	*sum = a + b;
	return (true);
}

bool	uf_hu_add(unsigned short a, unsigned short b, unsigned short *sum)
{
	if (USHRT_MAX - a < b)
		return (M_ERROR(false, "Unsigned short overflow"));
	*sum = a + b;
	return (true);
}

bool	uf_u_add(unsigned int a, unsigned int b, unsigned int *sum)
{
	if (UINT_MAX - a < b)
		return (M_ERROR(false, "Unsigned int overflow"));
	*sum = a + b;
	return (true);
}
