/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_lock.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:21:07 by qperez            #+#    #+#             */
/*   Updated: 2014/11/20 20:45:52 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_lock prototype>
** Copyright (C) <2013>  Quentin Perez <qperez42@gmail.com>
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

#ifndef S_LOCK_H
# define S_LOCK_H

# include <pthread.h>
# include <stdbool.h>

typedef enum			e_type_lock
{
	e_lock_default = PTHREAD_MUTEX_DEFAULT,
	e_lock_normal = PTHREAD_MUTEX_NORMAL,
	e_lock_errorcheck = PTHREAD_MUTEX_ERRORCHECK,
	e_lock_recursive = PTHREAD_MUTEX_RECURSIVE
}						t_type_lock;

typedef struct			s_lock
{
	void				*data;
	pthread_mutex_t		lock;
}						t_lock;

# define D_LOCK(funct)				f_lock_##funct

bool					f_lock_init(t_lock *v_this, void *data,
									t_type_lock type);
bool					f_lock_lock(t_lock *v_this, void **data);
bool					f_lock_release(t_lock *v_this, void **data);
bool					f_lock_destroy(t_lock *v_this);

#endif
