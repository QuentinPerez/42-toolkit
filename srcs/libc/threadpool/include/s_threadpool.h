/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_threadpool.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/05 13:33:01 by qperez            #+#    #+#             */
/*   Updated: 2014/07/05 13:34:53 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_threadpool prototype>
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

#ifndef S_THREADPOOL_H
# define S_THREADPOOL_H

# include <stdbool.h>
# include <stddef.h>
# include <lock/s_lock.h>
# include <queue/s_queue.h>

typedef struct	s_threadpool_data
{
	bool	v_run;
	t_queue	v_tasks;
}				t_threadpool_data;

typedef struct	s_threadpool_task
{
	void	(*f_funct)(void *);
	void	*v_data;
}				t_threadpool_task;

typedef struct	s_threadpool
{
	pthread_t			*v_id;
	size_t				v_nb_thread;
	t_threadpool_data	pv_data;
	t_lock				v_data;
}				t_threadpool;

# define	D_THREADPOOL(funct)	f_threadpool_##funct

bool	f_threadpool_init(t_threadpool *v_this, size_t nb_threads);
bool	f_threadpool_add_task(t_threadpool *v_this, t_threadpool_task *task);
void	f_threadpool_destroy(t_threadpool *v_this);

#endif
