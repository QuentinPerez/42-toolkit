/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_fdnotify.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 09:37:51 by qperez            #+#    #+#             */
/*   Updated: 2014/12/04 10:31:49 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains fdnotify prototype>
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

#ifndef S_FDNOTIFY_H
# define S_FDNOTIFY_H

# include <stdbool.h>
# include <sys/select.h>
# include <list/s_list.h>
# include <fdnotify/s_fdnotify_event.h>

typedef struct		s_fdnotify
{
	fd_set			v_read;
	fd_set			v_write;
	int				v_max;
	struct timeval	*p_timeout;
	struct timeval	v_timeout;
	struct timeval	v_savetimeout;
}					t_fdnotify;

# define D_FDNOTIFY(funct)	f_fdnotify_##funct

bool				f_fdnotify_init(t_fdnotify *v_this);
void				f_fdnotify_enable_timeout(t_fdnotify *v_this, int seconds,
											int useconds);
void				f_fdnotify_disable_timeout(t_fdnotify *v_this);
bool				f_fdnotify_get_event(t_fdnotify *v_this,
										t_fdnotify_event *ev, t_list *list,
										int *nb_interaction);
void				f_fdnotify_destroy(t_fdnotify *v_this);

#endif
