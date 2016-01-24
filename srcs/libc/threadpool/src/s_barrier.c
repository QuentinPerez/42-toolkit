/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_barrier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 13:15:11 by qperez            #+#    #+#             */
/*   Updated: 2016/01/24 16:02:46 by sfroment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains posix barrier function>
** < init, destroy, wait >
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

#include <threadpool/s_barrier.h>

bool	f_barrier_init(t_barrier *v_this, size_t count)
{
	if (count == 0)
	{
		errno = EINVAL;
		return (false);
	}
	if (pthread_mutex_init(&v_this->mutex, 0) != 0)
		return (false);
	if (pthread_cond_init(&v_this->cond, 0) != 0)
	{
		pthread_mutex_destroy(&v_this->mutex);
		return (false);
	}
	v_this->nb_waiting = count;
	v_this->max = 0;
	return (true);
}

bool	f_barrier_destroy(t_barrier *v_this)
{
	if (pthread_cond_destroy(&v_this->cond) != 0
		|| pthread_mutex_destroy(&v_this->mutex) != 0)
		return (false);
	return (true);
}

int		f_barrier_wait(t_barrier *v_this)
{
	if (pthread_mutex_lock(&v_this->mutex) != 0)
		return (-1);
	v_this->nb_waiting = v_this->nb_waiting + 1;
	if (v_this->nb_waiting >= v_this->max)
	{
		v_this->nb_waiting = 0;
		if (pthread_cond_broadcast(&v_this->cond) != 0)
		{
			pthread_mutex_unlock(&v_this->mutex);
			return (-1);
		}
		pthread_mutex_unlock(&v_this->mutex);
		return (1);
	}
	if (pthread_cond_wait(&v_this->cond, &(v_this->mutex)) != 0)
	{
		pthread_mutex_unlock(&v_this->mutex);
		return (-1);
	}
	pthread_mutex_unlock(&v_this->mutex);
	return (0);
}
