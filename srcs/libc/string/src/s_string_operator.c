/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/28 13:28:29 by qperez            #+#    #+#             */
/*   Updated: 2013/10/28 13:51:14 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_string_operator function>
** < erase >
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

#include <string/s_string.h>
#include <f_memory/f_memory.h>

void	f_string_erase(t_string *v_this, ui form, ui to)
{
	ui	size;

	if (form >= to || to >= v_this->v_size)
		return ;
	size = v_this->v_size - to;
	uf_memcpy(v_this->v_str + form, v_this->v_str + to, size);
	uf_memset(v_this->v_str + form + size, '\0', to - form);
	v_this->v_size = v_this->v_size - (to - form);
}
