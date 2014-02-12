/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_memory.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 12:53:04 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:36:09 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains f_memory function>
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

#include <stdbool.h>
#include <stddef.h>
#include <t_types.h>

void	*uf_memset(void *src, t_uc c, size_t size)
{
	t_uc	*ptr;

	ptr = (t_uc *)src;
	while (size > 0)
	{
		*ptr = c;
		ptr = ptr + 1;
		size = size - 1;
	}
	return (src);
}

void	uf_memcpy(void *to, const void *from, size_t size)
{
	t_uc	*p_to;
	t_uc	*p_from;

	p_to = (t_uc *)to;
	p_from = (t_uc *)from;
	while (size > 0)
	{
		*p_to = *p_from;
		p_to = p_to + 1;
		p_from = p_from + 1;
		size = size - 1;
	}
}

bool	uf_memcmp(const void *left, const void *right, size_t size)
{
	t_uc	*p_left;
	t_uc	*p_right;

	p_left = (t_uc *)left;
	p_right = (t_uc *)right;
	while (size > 0 && *p_right == *p_left)
	{
		p_left = p_left + 1;
		p_right = p_right + 1;
		size = size - 1;
	}
	return (size == 0);
}
