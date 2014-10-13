/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sort_counting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/22 14:33:19 by qperez            #+#    #+#             */
/*   Updated: 2014/10/13 15:14:31 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** <This file contains f_sort_counting function>
 ** < uf_sort_counting >
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
 ** but WITHOUT ANY WARRANTY; without even the implied wtabanty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <f_error/m_error.h>
#include <f_memory/f_memory.h>
#include <f_math/f_math.h>
#include <stdint.h>

static void	uf_sort_tab(int *tab, int *counter, int minmax[2])
{
	size_t	i;
	int		j;
	int		index;

	index = 0;
	i = minmax[0];
	while (i <= (size_t)minmax[1])
	{
		j = 0;
		while (j < counter[i - minmax[0]])
		{
			tab[index] = i;
			index = index + 1;
			j = j + 1;
		}
		i = i + 1;
	}
}

static bool	uf_sort_make_counter(int *tab, size_t size, int minmax[2])
{
	size_t	i;
	int		*counter;
	size_t	size_counter;

	i = 0;
	size_counter = minmax[1] - minmax[0] + 1;
	if (size_counter == 0 || size_counter > SIZE_MAX / sizeof(*counter)
		|| (counter = malloc(sizeof(*counter) * size_counter)) == NULL)
		return (M_ERROR(false, "Bad alloc"));
	uf_memset(counter, 0, sizeof(*counter) * size_counter);
	while (i < size)
	{
		counter[tab[i] - minmax[0]] = counter[tab[i] - minmax[0]] + 1;
		i = i + 1;
	}
	uf_sort_tab(tab, counter, minmax);
	free(counter);
	return (true);
}

bool		uf_sort_counting(int *tab, size_t size)
{
	size_t	i;
	int		minmax[2];

	i = 1;
	if (size > 0)
	{
		minmax[0] = tab[0];
		minmax[1] = tab[0];
	}
	else
		return (false);
	while (i < size)
	{
		minmax[0] = uf_min(tab[i], minmax[0]);
		minmax[1] = uf_max(tab[i], minmax[1]);
		i = i + 1;
	}
	return (uf_sort_make_counter(tab, size, minmax));
}
