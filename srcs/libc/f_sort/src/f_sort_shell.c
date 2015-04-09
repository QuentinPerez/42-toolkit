/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sort_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/22 13:03:26 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:40:07 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains f_sort_shell function>
** < shell >
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

#include <stddef.h>

void	uf_sort_shell(int *begin, size_t size)
{
	size_t	h;
	size_t	i;
	size_t	j;
	int		tmp;

	h = size >> 1;
	while (h > 0)
	{
		i = h;
		while (i < size)
		{
			j = i;
			tmp = begin[i];
			while (j >= h && tmp < begin[j - h])
			{
				begin[j] = begin[j - h];
				j = j - h;
			}
			begin[j] = tmp;
			i = i + 1;
		}
		h = h >> 1;
	}
}
