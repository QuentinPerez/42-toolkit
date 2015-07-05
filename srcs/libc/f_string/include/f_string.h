/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_string.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/06 21:23:29 by qperez            #+#    #+#             */
/*   Updated: 2015/07/03 16:32:20 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains f_string function>
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

#ifndef F_STRING_H
# define F_STRING_H

# include <stddef.h>
# include <stdbool.h>

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
char	*uf_itoa(int nbr);
char	*uf_itoa_base(int nbr, size_t base);
int		uf_atoi(const char *nbr);
int		uf_atoi_base(const char *nbr, size_t base);
char	*uf_strdup(const char *str);
char	*uf_getstr(int fd, unsigned char terminate, bool del_terminate);
char	*uf_getline(int fd, bool del_terminate);
char	*uf_mapfile(const char *name, size_t *len, int mmap_flags, bool priv);
bool	uf_unmapfile(void *addr, size_t len);

#endif
