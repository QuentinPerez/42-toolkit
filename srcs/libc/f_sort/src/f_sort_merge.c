/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sort_merge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/23 13:43:18 by qperez            #+#    #+#             */
/*   Updated: 2015/07/03 16:38:25 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains f_sort_merge function>
** < merge >
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

#include <stdbool.h>
#include <f_error/m_error.h>
#include <f_secure/f_secure.h>
#include <f_sort/f_sort.h>
#include <stdint.h>

static inline void	uf_merge_assign(int *ptr, int *tmp, int *index, int *value)
{
	ptr[*index] = tmp[*value];
	*value = *value + 1;
	*index = *index + 1;
}

static void			uf_merge(int *ptr, int *tmp, int low, int high)
{
	int	left;
	int	right;
	int	index;
	int	mid;

	left = low;
	index = low;
	mid = (low + high) >> 1;
	right = mid + 1;
	while (left <= mid && right <= high)
	{
		if (tmp[left] <= tmp[right])
			uf_merge_assign(ptr, tmp, &index, &left);
		else
			uf_merge_assign(ptr, tmp, &index, &right);
	}
	right = 0;
	mid = mid - left + 1;
	while (right < mid)
	{
		ptr[index + right] = tmp[left + right];
		right = right + 1;
	}
}

static void			uf_recursive_merge(int *ptr, int *tmp, int low, int high)
{
	int	mid;
	int	i;

	if (low >= high)
		return ;
	i = low;
	mid = (low + high) >> 1;
	uf_recursive_merge(ptr, tmp, low, mid);
	uf_recursive_merge(ptr, tmp, mid + 1, high);
	while (i <= high)
	{
		tmp[i] = ptr[i];
		i = i + 1;
	}
	uf_merge(ptr, tmp, low, high);
}

bool				uf_sort_merge(int *ptr, size_t size)
{
	int	*tmp;

	if ((tmp = uf_malloc_s(size, sizeof(*tmp))) == NULL)
		return (M_ERROR(false, "Bad alloc"));
	uf_recursive_merge(ptr, tmp, 0, (int)size - 1);
	uf_free_s((void **)&tmp);
	return (true);
}
