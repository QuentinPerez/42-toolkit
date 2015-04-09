/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_fdnotify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 09:46:14 by qperez            #+#    #+#             */
/*   Updated: 2014/12/04 10:38:08 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains fdnotify method>
** < init, destroy, enable_timeout, disable_timeout >
** Copyright (C) <2014>  Quentin Perez <qperez42@gmail.com>
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

#include <fdnotify/s_fdnotify.h>

bool		f_fdnotify_init(t_fdnotify *v_this)
{
	v_this->p_timeout = NULL;
	return (true);
}

void		f_fdnotify_disable_timeout(t_fdnotify *v_this)
{
	v_this->p_timeout = NULL;
}

void		f_fdnotify_enable_timeout(t_fdnotify *v_this,
									int seconds, int useconds)
{
	v_this->v_timeout.tv_sec = seconds;
	v_this->v_timeout.tv_usec = useconds;
	v_this->v_savetimeout.tv_sec = seconds;
	v_this->v_savetimeout.tv_usec = useconds;
	v_this->p_timeout = &v_this->v_timeout;
}

void		f_fdnotify_destroy(t_fdnotify *v_this)
{
	FD_ZERO(&v_this->v_read);
	FD_ZERO(&v_this->v_write);
	v_this->v_max = -1;
}
