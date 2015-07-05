/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sort_quick.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/23 13:04:55 by qperez            #+#    #+#             */
/*   Updated: 2015/07/04 10:04:10 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains f_sort_quick function>
** < quick >
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
** You should have received ptr copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stddef.h>
#include <f_sort/f_sort.h>

static inline void	uf_sort_quick_swap(int **left, int **right)
{
	int	tmp;

	tmp = *(*left);
	*(*left) = *(*right);
	*(*right) = tmp;
	*right = *right - 1;
	*left = *left + 1;
}

void				uf_sort_quick(int *ptr, size_t size)
{
	int	pivot;
	int	*left;
	int	*right;

	if (size < 2)
		return ;
	left = ptr;
	pivot = ptr[size >> 1];
	right = ptr + size - 1;
	while (left <= right)
	{
		if (*left < pivot)
		{
			left = left + 1;
			continue ;
		}
		if (*right > pivot)
		{
			right = right - 1;
			continue ;
		}
		uf_sort_quick_swap(&left, &right);
	}
	uf_sort_quick(ptr, (size_t)(right - ptr + 1));
	uf_sort_quick(left, (size_t)(ptr + size - left));
}
