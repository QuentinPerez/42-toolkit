/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_fdnotify_event.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 09:42:41 by qperez            #+#    #+#             */
/*   Updated: 2014/12/04 10:17:23 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains fdnotify_event definition>
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

#ifndef S_FDNOTIFY_EVENT_H
# define S_FDNOTIFY_EVENT_H

typedef enum	e_fdnotify_type
{
	e_fdnotify_none = 0,
	e_fdnotify_read,
	e_fdnotify_write
}				t_fdnotify_type;

typedef struct	s_fdnotify_event
{
	int				v_fd;
	void			*v_data;
	t_fdnotify_type	v_type;
}				t_fdnotify_event;

#endif
