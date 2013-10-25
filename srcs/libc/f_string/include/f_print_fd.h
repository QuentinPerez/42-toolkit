/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_fd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 15:11:46 by qperez            #+#    #+#             */
/*   Updated: 2013/10/25 17:05:24 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains all f_print_fd prototype>
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

#ifndef F_PRINT_FD_H
# define F_PRINT_FD_H

#include <unistd.h>
#include <t_types.h>

ssize_t	uf_print_char_fd(char c, int fd);
ssize_t	uf_print_str_fd(const char *str, int fd);
void	uf_print_nbr_fd(ssize_t nb, int fd);
void	uf_print_floating_nbr_fd(double nbr, ui digit, int fd);
void	uf_print_nbr_base_fd(ssize_t nbr, int fd, ssize_t base);
void	uf_print_addr_fd(void *addr, int fd);

#endif
