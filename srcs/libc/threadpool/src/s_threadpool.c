/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_threadpool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/05 13:35:11 by qperez            #+#    #+#             */
/*   Updated: 2014/10/13 15:31:37 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_threadpool function>
** < init, destroy >
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

#include <stdint.h>
#include <threadpool/s_threadpool.h>
#include <f_error/m_error.h>
#include <f_memory/f_memory.h>
#include <stdlib.h>
#include <unistd.h>

static void	*f_threadpool_routine(void *arg)
{
	t_threadpool_data	*data;
	t_threadpool		*v_this;
	t_threadpool_task	*task;
	bool				run;

	run = true;
	v_this = (t_threadpool *)arg;
	while (run == true)
	{
		if (D_LOCK(lock)(&v_this->v_data, (void **)&data) == true)
		{
			run = data->v_run;
			task = D_QUEUE(pop)(&data->v_tasks);
			D_LOCK(release)(&v_this->v_data, (void **)&data);
			if (run == true && task != NULL)
			{
				task->f_funct(task->v_data);
				free(task);
			}
		}
		usleep(5000);
	}
	return (NULL);
}

static bool	f_threadpool_create(t_threadpool *v_this, t_threadpool_data *data,
								size_t nb_thread)
{
	size_t	i;

	i = 0;
	while (i < nb_thread)
	{
		if (pthread_create(&v_this->v_id[i], NULL,
							D_THREADPOOL(routine), v_this) != 0)
			break ;
		i = i + 1;
	}
	if (i == nb_thread)
		data->v_run = true;
	v_this->v_nb_thread = i;
	D_LOCK(release)(&v_this->v_data, (void **)&data);
	if (i != nb_thread)
	{
		D_THREADPOOL(destroy)(v_this);
		return (M_ERROR(false, "Couldn't create thread"));
	}
	return (true);
}

bool		f_threadpool_init(t_threadpool *v_this, size_t nb_thread)
{
	t_threadpool_data	*data;

	v_this->pv_data.v_run = false;
	if (nb_thread > SIZE_MAX / sizeof(*v_this->v_id)
		|| (v_this->v_id = malloc(sizeof(*v_this->v_id) * nb_thread)) == NULL)
		return (M_ERROR(false, "Bad alloc"));
	D_QUEUE(init)(&v_this->pv_data.v_tasks, free);
	if (D_LOCK(init)(&v_this->v_data, &v_this->pv_data) == false)
	{
		free(v_this->v_id);
		return (M_ERROR(false, "Couldn't initialize lock"));
	}
	if (D_LOCK(lock)(&v_this->v_data, (void **)&data) == true)
		return (D_THREADPOOL(create)(v_this, data, nb_thread));
	D_LOCK(destroy)(&v_this->v_data);
	free(v_this->v_id);
	return (M_ERROR(false, "An error has occured"));
}

bool		f_threadpool_add_task(t_threadpool *v_this,
									t_threadpool_task *task)
{
	t_threadpool_task	*add;
	t_threadpool_data	*data;

	if ((add = malloc(sizeof(*add))) == NULL)
		return (M_ERROR(false, "Bad alloc"));
	uf_memcpy(add, task, sizeof(*add));
	if (D_LOCK(lock)(&v_this->v_data, (void **)&data) == true)
	{
		if (D_QUEUE(push)(&data->v_tasks, add) == false)
		{
			free(add);
			D_LOCK(release)(&v_this->v_data, (void **)&data);
			return (M_ERROR(false, "Couldn't add tasks"));
		}
		D_LOCK(release)(&v_this->v_data, (void **)&data);
		return (true);
	}
	free(add);
	return (false);
}

void		f_threadpool_destroy(t_threadpool *v_this)
{
	size_t				i;
	t_threadpool_data	*data;

	i = 0;
	if (D_LOCK(lock)(&v_this->v_data, (void **)&data) == true)
	{
		data->v_run = false;
		D_LOCK(release)(&v_this->v_data, (void **)&data);
	}
	while (i < v_this->v_nb_thread)
	{
		if (pthread_join(v_this->v_id[i], NULL) != 0)
			M_INFOS("pthread_join error");
		i = i + 1;
	}
	D_LOCK(destroy)(&v_this->v_data);
	D_QUEUE(destroy)(&v_this->pv_data.v_tasks);
	free(v_this->v_id);
}
