/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_interval.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/10 14:30:45 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/08 17:55:50 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains all s_list_interval function>
** < init, begin, end >
** Copyright (C) <2013>  Iohann Rabeson <irabeson42@gmail.com>
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

#include <list/s_list_interval.h>

void		f_list_interval_init(t_list_interval *v_this, t_list_cell *begin,
								t_list_cell *end)
{
	v_this->v_begin = begin;
	v_this->v_end = end;
}

t_list_cell	*f_list_interval_begin(const t_list_interval *v_this)
{
	return (v_this->v_begin);
}

t_list_cell	*f_list_interval_end(const t_list_interval *v_this)
{
	return (v_this->v_end);
}
