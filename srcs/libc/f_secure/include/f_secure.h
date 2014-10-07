/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_secure.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/07 19:52:49 by qperez            #+#    #+#             */
/*   Updated: 2014/10/07 19:52:51 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains all secure prototype>
** Copyright (C) <2014>  Quentin Perez <qperez42@gmail.com>
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

#ifndef F_SECURE_H
# define F_SECURE_H

# include <stdbool.h>

bool    uf_hhu_add(unsigned char a, unsigned char b, unsigned char *sum);
bool    uf_hu_add(unsigned short a, unsigned short b, unsigned short *sum);
bool    uf_u_add(unsigned int a, unsigned int b, unsigned int *sum);

bool    uf_hhu_sub(unsigned char a, unsigned char b, unsigned char *sum);
bool    uf_hu_sub(unsigned short a, unsigned short b, unsigned short *sum);
bool    uf_u_sub(unsigned int a, unsigned int b, unsigned int *sum);

bool    uf_hhu_mul(unsigned char a, unsigned char b, unsigned char *sum);
bool    uf_hu_mul(unsigned short a, unsigned short b, unsigned short *sum);
bool    uf_u_mul(unsigned int a, unsigned int b, unsigned int *sum);

#endif
