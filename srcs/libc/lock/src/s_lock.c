/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_lock.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:20:45 by qperez            #+#    #+#             */
/*   Updated: 2014/03/19 15:37:20 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_lock method>
** < init, destroy, lock, release >
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

#include <lock/s_lock.h>
#include <f_error/m_error.h>

bool	f_lock_init(t_lock *v_this, void *data)
{
	if (pthread_mutex_init(&v_this->lock, NULL) != 0)
		return (M_ERROR(false, "Fail init lock"));
	v_this->data = data;
	return (true);
}

bool	f_lock_lock(t_lock *v_this, void **data)
{
	if (pthread_mutex_lock(&v_this->lock) != 0)
		return (M_ERROR(false, "Bad lock"));
	*data = v_this->data;
	return (true);
}

bool	f_lock_release(t_lock *v_this, void **data)
{
	if (pthread_mutex_unlock(&v_this->lock) != 0)
		return (M_ERROR(false, "Fail unlock"));
	*data = NULL;
	return (true);
}

bool	f_lock_destroy(t_lock *v_this)
{
	return (!(pthread_mutex_destroy(&v_this->lock) != 0));
}
