/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_capacity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/30 17:43:18 by qperez            #+#    #+#             */
/*   Updated: 2013/09/02 22:36:22 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This function contains all s_list_capacity method>
** < empty, size >
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

#include <s_list.h>

inline bool	f_list_empty(const t_list *v_this)
{
	return (v_this->v_size == 0);
}

inline uint	f_list_size(const t_list *v_this)
{
	return (v_this->v_size);
}

