/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/29 17:32:48 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:36:31 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains f_print function>
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

#ifndef F_PRINT_H
# define F_PRINT_H

# include <unistd.h>
# include <t_types.h>
# include <stdbool.h>

ssize_t	uf_print_char(char c);
ssize_t	uf_print_str(const char *str);
void	uf_print_nstr(const char *str, t_ui size);
void	uf_print_nbr(ssize_t nb);
void	uf_print_color(t_ui color);
void	uf_print_color_fx(t_ui color, t_ui fx);
void	uf_print_bits(size_t value, size_t size);
void	uf_print_floating_nbr(double nbr, t_ui digit);
void	uf_print_nbr_base(ssize_t nbr, ssize_t base);
void	uf_print_variadic(const char *fmt, ...);
void	uf_print_addr(void *addr);
void	uf_print_bool(bool value);

#endif
