/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_barrier.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 13:13:01 by qperez            #+#    #+#             */
/*   Updated: 2016/01/24 16:02:32 by sfroment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains barrier prototype>
** Copyright (C) <2015>  Quentin Perez <qperez42@gmail.com>
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

#ifndef S_BARRIER_H
# define S_BARRIER_H

# include <pthread.h>
# include <errno.h>
# include <stdbool.h>

typedef struct		s_barrier
{
	pthread_mutex_t	mutex;
	pthread_cond_t	cond;
	size_t			nb_waiting;
	size_t			max;
}					t_barrier;

bool				f_barrier_init(t_barrier *v_this, size_t count);
bool				f_barrier_destroy(t_barrier *v_this);
int					f_barrier_wait(t_barrier *v_this);

# define D_BARRIER(func)	f_barrier_##func

#endif
