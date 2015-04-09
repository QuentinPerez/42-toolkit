/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_mul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/07 20:10:06 by qperez            #+#    #+#             */
/*   Updated: 2015/04/09 15:20:14 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains uf_*mul functions>
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

bool	uf_hhu_mul(unsigned char a, unsigned char b, unsigned char *sum)
{
	if (a > UCHAR_MAX / b)
		return (M_ERROR(false, "Unsigned char overflow"));
	*sum = a * b;
	return (true);
}

bool	uf_hu_mul(unsigned short a, unsigned short b, unsigned short *sum)
{
	if (a > USHRT_MAX / b)
		return (M_ERROR(false, "Unsigned short overflow"));
	*sum = a * b;
	return (true);
}

bool	uf_u_mul(unsigned int a, unsigned int b, unsigned int *sum)
{
	if (a > UINT_MAX / b)
		return (M_ERROR(false, "Unsigned int overflow"));
	*sum = a * b;
	return (true);
}
