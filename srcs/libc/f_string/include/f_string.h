/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_string.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/06 21:23:29 by qperez            #+#    #+#             */
/*   Updated: 2013/10/07 23:37:40 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains all f_string function>
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

#ifndef F_STRING_H
# define F_STRING_H

#include <stddef.h>

char	*uf_strcpy(char *dest, const char *src);
char	*uf_strncpy(char *dest, const char *src, size_t size);
size_t	uf_strlcpy(char *dest, const char *src, size_t size);
char	*uf_strcat(char *dest, const char *src);
char	*uf_strncat(char *dest, const char *src, size_t size);
size_t	uf_strlcat(char *dest, const char *src, size_t size);
int		uf_strcmp(const char *left, const char *right);
int		uf_strncmp(const char *left, const char *right, size_t count);
int		uf_str_case_cmp(const char *left, const char *right);
int		uf_str_case_ncmp(const char *left, const char *right, size_t count);

#endif
