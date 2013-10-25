/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/29 17:32:48 by qperez            #+#    #+#             */
/*   Updated: 2013/10/25 17:05:33 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains all f_print function>
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

#include <f_string/f_print_fd.h>
#include <unistd.h>

ssize_t	uf_print_char(char c);
ssize_t	uf_print_str(const char *str);
void	uf_print_nbr(ssize_t nb);
void	uf_print_floating_nbr(double nbr, ui digit);
void	uf_print_nbr_base(ssize_t nbr, ssize_t base);
void	uf_print_addr(void *addr);

#endif
