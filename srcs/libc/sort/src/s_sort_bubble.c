/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sort_bubble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/18 12:23:14 by qperez            #+#    #+#             */
/*   Updated: 2013/10/18 12:47:57 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_sort_bubble function>
** < bubble >
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

#include <s_sort.h>

void	f_sort_bubble(t_sort *v_this, void *begin, ui size)
{
	ui	x;
	ui	y;
	uc	*right;
	uc	*left;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size - 1)
		{
			left = (uc*)begin + (y * v_this->v_sizeof);
			right = left + v_this->v_sizeof;
			if (v_this->f_cmp(left, right) == true)
				v_this->f_swap(left, right);
			y = y + 1;
		}
		x = x + 1;
	}
}
