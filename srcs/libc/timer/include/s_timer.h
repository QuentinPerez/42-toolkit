/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_timer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/16 12:39:48 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:53:28 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_timer prototype>
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

#ifndef S_TIMER_H
# define S_TIMER_H

# include <stdbool.h>
# include <stddef.h>
# include <sys/time.h>

typedef struct	s_timer
{
	bool			v_paused;
	bool			v_started;
	struct timeval	v_start;
	struct timeval	v_pause;
}				t_timer;

# define D_TIMER(funct)	f_timer_##funct

void	f_timer_start(t_timer *v_this);
void	f_timer_stop(t_timer *v_this);
void	f_timer_pause(t_timer *v_this);
void	f_timer_unpause(t_timer *v_this);
size_t	f_timer_get_ticks(t_timer *v_this);
bool	f_timer_is_started(const t_timer *v_this);
bool	f_timer_is_paused(const t_timer *v_this);

#endif
