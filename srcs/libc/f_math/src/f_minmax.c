/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_minmax.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/22 11:46:25 by qperez            #+#    #+#             */
/*   Updated: 2013/10/22 11:50:04 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains f_minmax function>
** < uf_min, uf_max >
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

extern inline double	uf_min(const double x, const double y)
{
	if (x > y)
		return (y);
	return (x);
}

extern inline double	uf_max(const double x, const double y)
{
	if (x > y)
		return (x);
	return (y);
}