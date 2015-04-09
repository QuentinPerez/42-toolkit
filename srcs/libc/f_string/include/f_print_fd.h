/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_fd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 15:11:46 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:37:10 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains f_print_fd prototype>
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

#ifndef F_PRINT_FD_H
# define F_PRINT_FD_H

# include <unistd.h>
# include <stddef.h>
# include <stdbool.h>

ssize_t	uf_print_char_fd(char c, int fd);
ssize_t	uf_print_str_fd(const char *str, int fd);
ssize_t	uf_print_nstr_fd(const char *str, size_t size, int fd);
void	uf_print_nbr_fd(ssize_t nb, int fd);
void	uf_print_bits_fd(size_t value, size_t size, int fd);
void	uf_print_floating_nbr_fd(double nbr, size_t digit, int fd);
void	uf_print_nbr_base_fd(ssize_t nbr, ssize_t base, int fd);
void	uf_print_variadic_fd(int fd, const char *fmt, ...);
void	uf_print_addr_fd(void *addr, int fd);
void	uf_print_bool_fd(bool value, int fd);

#endif
