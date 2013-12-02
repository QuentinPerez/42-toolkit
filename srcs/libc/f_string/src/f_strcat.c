/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strcat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/06 22:29:30 by qperez            #+#    #+#             */
/*   Updated: 2013/11/20 14:20:02 by qperez           ###   ########.fr       */
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

char		*uf_strcat(char *dest, const char *src)
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

char		*uf_strncat(char *dest, const char *src, size_t size)
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

static char	*uf_goto_end(char *p_dest, size_t tmp)
{
	while (*p_dest != '\0' && tmp != 0)
	{
		p_dest = p_dest + 1;
		tmp = tmp - 1;
	}
	return (p_dest);
}

size_t		uf_strlcat(char *dest, const char *src, size_t size)
{
	char		*p_dest;
	const char	*p_src;
	size_t		tmp;
	size_t		dlen;

	tmp = size;
	p_src = src;
	p_dest = dest;
	p_dest = uf_goto_end(p_dest, tmp);
	dlen = p_dest - dest;
	tmp = size - dlen;
	if (tmp == 0)
		return (dlen + uf_str_len(p_src));
	while (*p_src != '\0')
	{
		if (tmp != 1)
		{
			*p_dest = *p_src;
			p_dest = p_dest + 1;
			tmp = tmp - 1;
		}
		p_src = p_src + 1;
	}
	*p_dest = '\0';
	return (dlen + (p_src - src));
}
