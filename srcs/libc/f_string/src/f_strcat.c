/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strcat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/06 22:29:30 by qperez            #+#    #+#             */
/*   Updated: 2013/11/03 23:52:42 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains f_strcat function>
** < uf_strcat, uf_strncat, uf_strlcat >
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

#include <stddef.h>
#include <f_string/f_str_tools.h>
#include <f_memory/f_memory.h>

char	*uf_strcat(char *dest, const char *src)
{
	char	*tmp;

	tmp = dest;
	while (*dest != '\0')
		dest = dest + 1;
	while (*src != '\0')
	{
		*dest = *src;
		dest = dest + 1;
		src = src + 1;
	}
	*dest = *src;
	return (tmp);
}

char	*uf_strncat(char *dest, const char *src, size_t size)
{
	char	*tmp;

	tmp = dest;
	if (size != 0)
	{
		while (*dest != '\0')
			dest = dest + 1;
		while (*src != '\0' && size != 0)
		{
			*dest = *src;
			dest = dest + 1;
			src = src + 1;
			size = size - 1;
		}
		*dest = '\0';
	}
	return (tmp);
}

size_t	uf_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_size;
	size_t	len;
	size_t	ret;

	dest_size = uf_str_len(dest);
	len = uf_str_len(src);
	ret = dest_size + len;
	dest = dest + dest_size;
	size = size - dest_size;
	if (len >= size)
		len = size - 1;
	uf_memcpy(dest, src, len);
	dest[len] = '\0';
	return (ret);
}
