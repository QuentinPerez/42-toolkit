/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_timer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/16 12:38:55 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:53:18 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_timer function>
** < start, stop, pause, unpause, get_ticks >
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

#include <timer/s_timer.h>
#include <stddef.h>

void	f_timer_start(t_timer *v_this)
{
	v_this->v_started = true;
	v_this->v_paused = false;
	gettimeofday(&v_this->v_start, NULL);
}

void	f_timer_stop(t_timer *v_this)
{
	v_this->v_started = false;
	v_this->v_paused = false;
}

void	f_timer_pause(t_timer *v_this)
{
	struct timeval	tmp;

	if (v_this->v_started == true && v_this->v_paused == false)
	{
		v_this->v_paused = true;
		gettimeofday(&tmp, NULL);
		v_this->v_pause.tv_sec = tmp.tv_sec - v_this->v_start.tv_sec;
		v_this->v_pause.tv_usec = tmp.tv_usec - v_this->v_start.tv_usec;
	}
}

void	f_timer_unpause(t_timer *v_this)
{
	struct timeval	tmp;

	if (v_this->v_paused == true)
	{
		v_this->v_paused = false;
		gettimeofday(&tmp, NULL);
		v_this->v_start.tv_sec = tmp.tv_sec - v_this->v_pause.tv_sec;
		v_this->v_start.tv_usec = tmp.tv_usec - v_this->v_pause.tv_usec;
		v_this->v_pause.tv_sec = 0;
		v_this->v_pause.tv_usec = 0;
	}
}

t_ui	f_timer_get_ticks(t_timer *v_this)
{
	struct timeval	tmp;

	if (v_this->v_started == false)
		return (0);
	if (v_this->v_paused == true)
		return (v_this->v_pause.tv_sec * 1000 + v_this->v_pause.tv_usec / 1000);
	gettimeofday(&tmp, NULL);
	return ((tmp.tv_sec * 1000 + tmp.tv_usec / 1000) -
			(v_this->v_start.tv_sec * 1000 + v_this->v_start.tv_usec / 1000));
}
