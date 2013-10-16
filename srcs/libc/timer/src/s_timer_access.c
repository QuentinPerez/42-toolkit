/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_timer_access.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/16 12:49:23 by qperez            #+#    #+#             */
/*   Updated: 2013/10/16 12:54:14 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_timer_access function>
** < is_started, is_paused >
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

#include <s_timer.h>

bool	f_timer_is_paused(t_timer *v_this)
{
	return (v_this->v_paused == true);
}

bool	f_timer_is_started(t_timer *v_this)
{
	return (v_this->v_started == true);
}
