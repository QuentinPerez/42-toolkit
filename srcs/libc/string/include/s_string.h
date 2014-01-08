/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/22 12:13:53 by qperez            #+#    #+#             */
/*   Updated: 2014/01/08 12:32:52 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_string prototype>
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

#ifndef S_STRING_H
# define S_STRING_H

# include <stdbool.h>
# include <t_types.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_string
{
	char		*v_str;
	ui			v_size;
	ui			v_capacity;
	const char	*v_hex;
	ui			(*f_realloc)(ui size);
}				t_string;

# define D_STRING(funct)	f_string_##funct

bool		f_string_init(t_string *v_this, ui (*uf_realloc)(ui size));
void		f_string_print(const t_string *v_this);
void		f_string_print_fd(const t_string *v_this, ui fd);
void		f_string_print_memory(const t_string *v_this, const char *name);
char		*f_string_dup(const t_string *v_this);
const char	*f_string_str(const t_string *v_this);
ui			f_string_capacity(const t_string *v_this);
bool		f_string_empty(const t_string *v_this);
ui			f_string_size(const t_string *v_this);
void		f_string_clear(t_string *v_this);
bool		f_string_add_str(t_string *v_this, const char *str);
bool		f_string_add_nstr(t_string *v_this, const char *str, ui size);
bool		f_string_add_char(t_string *v_this, uc c);
bool		f_string_add_nbr(t_string *v_this, ssize_t nbr);
bool		f_string_add_ptr(t_string *v_this, void *addr);
bool		f_string_add_nbr_base(t_string *v_this, ssize_t nbr, ui base);
bool		f_string_add_color(t_string *v_this, ui color, ui fx);
bool		f_string_variadic(t_string *v_this, const char *fmt, ...);
bool		f_string_variadic_list(t_string *v_this, const char *fmt,
								   va_list *ap);
char		**f_string_split(t_string *v_this, const char *charset);
void		f_string_erase(t_string *v_this, ui from, ui to);
bool		f_string_insert(t_string *v_this, const char *insert, ui at);
void		f_string_destroy(t_string *v_this);

#endif
