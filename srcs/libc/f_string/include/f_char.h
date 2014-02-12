/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_char.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/07 21:03:48 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:31:51 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains f_char function>
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

#ifndef F_CHAR_H
# define F_CHAR_H

# include <stdbool.h>
# include <t_types.h>

bool	uf_is_upper(const t_uc c);
bool	uf_is_lower(const t_uc c);
t_uc	uf_to_lower(const t_uc c);
t_uc	uf_to_upper(const t_uc c);
bool	uf_is_alpha(const t_uc c);
bool	uf_is_printable(const t_uc c);
bool	uf_is_digit(const t_uc c);

#endif
