/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_crypto_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/20 16:02:05 by irabeson          #+#    #+#             */
/*   Updated: 2015/07/03 16:57:46 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains f_crypto_rot function>
** < rot5, rot13, rot18, rot47 >
** Copyright (C) <2013>  Iohann Rabeson <irabeson42@gmail.com>
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

#include <f_string/f_str_tools.h>
#include <f_crypto/f_crypto.h>

static inline char	uf_rotate(char c, int n, char base)
{
	return ((((c - base) + (char)n) % ((char)n << 1)) + base);
}

void				uf_crypto_rot5(char *str)
{
	while (*str != '\0')
	{
		if (*str > 47 && *str < 58)
			*str = uf_rotate(*str, 5, '0');
		str = str + 1;
	}
}

void				uf_crypto_rot13(char *str)
{
	while (*str != '\0')
	{
		if (*str > 96 && *str < 123)
			*str = uf_rotate(*str, 13, 'a');
		else if (*str > 64 && *str < 91)
			*str = uf_rotate(*str, 13, 'A');
		str = str + 1;
	}
}

void				uf_crypto_rot18(char *str)
{
	uf_crypto_rot5(str);
	uf_crypto_rot13(str);
}

void				uf_crypto_rot47(char *str)
{
	while (*str != '\0')
	{
		if (*str > 32 && *str < 127)
			*str = uf_rotate(*str, 47, '!');
		str = str + 1;
	}
}
