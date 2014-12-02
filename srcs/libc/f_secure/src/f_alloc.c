/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_alloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 10:14:09 by qperez            #+#    #+#             */
/*   Updated: 2014/12/02 10:36:04 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains alloc_s functions>
** Copyright (C) <2014>  Quentin Perez <qperez42@gmail.com>
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

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <f_error/m_error.h>

void	*uf_malloc_s(size_t nbr, size_t size)
{
	if (size == 0 || nbr == 0 || nbr > SIZE_MAX / size)
		return ((void *)M_ERROR(0, "Bad size malloc"));
	return (malloc(size * nbr));
}

void	*uf_calloc_s(size_t nbr, size_t size)
{
	if (size == 0 || nbr == 0 || nbr > SIZE_MAX / size)
		return ((void *)M_ERROR(0, "Bad size calloc"));
	return (calloc(nbr, size));
}

void	*uf_realloc_s(void *ptr, size_t nbr, size_t size)
{
	if (size == 0 || nbr == 0 || nbr > SIZE_MAX / size)
		return ((void *)M_ERROR(0, "Bad size realloc"));
	return (realloc(ptr, nbr * size));
}

void	uf_free_s(void **ptr)
{
	if (*ptr == NULL)
		M_INFOS("ptr == NULL");
	free(*ptr);
	*ptr = NULL;
}
