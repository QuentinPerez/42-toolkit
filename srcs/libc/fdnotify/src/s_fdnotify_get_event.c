/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_fdnotify_get_event.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 10:37:11 by qperez            #+#    #+#             */
/*   Updated: 2014/12/04 10:37:44 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains fdnotify method>
** < get_event >
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

#include <f_memory/f_memory.h>
#include <fdnotify/s_fdnotify.h>
#include <fdnotify/s_fdnotify_cell.h>

static void	f_fdnotify_init_select(t_fdnotify *v_this, t_list *list)
{
	t_list_cell		*cell;
	t_fdnotify_cell	*notify_cell;

	FD_ZERO(&v_this->v_read);
	FD_ZERO(&v_this->v_write);
	v_this->v_max = -1;
	cell = D_LIST(begin)(list);
	while (cell != NULL)
	{
		notify_cell = (t_fdnotify_cell *)cell->v_data;
		if (notify_cell->v_fd > v_this->v_max)
			v_this->v_max = notify_cell->v_fd + 1;
		FD_SET(notify_cell->v_fd, &v_this->v_read);
		if (notify_cell->v_add_to_write == true)
			FD_SET(notify_cell->v_fd, &v_this->v_write);
		cell = cell->v_next;
	}
}

static bool	f_fdnotify_create_event(t_fdnotify *v_this, t_fdnotify_cell *notif,
														t_fdnotify_event *event)
{
	if (FD_ISSET(notif->v_fd, &v_this->v_write) != 0)
	{
		event->v_fd = notif->v_fd;
		event->v_data = notif;
		event->v_type = e_fdnotify_write;
		notif->v_add_to_write = false;
		return (true);
	}
	else if (FD_ISSET(notif->v_fd, &v_this->v_read) != 0)
	{
		event->v_fd = notif->v_fd;
		event->v_data = notif;
		event->v_type = e_fdnotify_read;
		return (true);
	}
	return (false);
}

static void	f_fdnotify_reset_timeout(t_fdnotify *v_this)
{
	v_this->v_timeout.tv_sec = v_this->v_savetimeout.tv_sec;
	v_this->v_timeout.tv_usec = v_this->v_savetimeout.tv_usec;
}

bool		f_fdnotify_get_event(t_fdnotify *v_this, t_fdnotify_event *ev,
								t_list *list, int *nb_interaction)
{
	int				rselect;
	t_list_cell		*cell;

	uf_memset(ev, 0, sizeof(*ev));
	D_FDNOTIFY(init_select)(v_this, list);
	if ((rselect = select(v_this->v_max, &v_this->v_read, &v_this->v_write,
									NULL, v_this->p_timeout)) != -1)
	{
		cell = D_LIST(begin)(list);
		while (cell != NULL)
		{
			if (D_FDNOTIFY(create_event)(v_this, cell->v_data, ev) == true)
				break ;
			cell = cell->v_next;
		}
	}
	D_FDNOTIFY(reset_timeout)(v_this);
	if (nb_interaction != NULL)
		*nb_interaction = rselect;
	return (rselect != -1);
}
