/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_fdnotify_cell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 11:21:46 by qperez            #+#    #+#             */
/*   Updated: 2014/12/04 10:21:55 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains fdnotify_cell method>
** < init, destroy>
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

#include <fdnotify/s_fdnotify_cell.h>
#include <unistd.h>

bool	f_fdnotify_cell_init(t_fdnotify_cell *v_this, int fd)
{
	v_this->v_fd = fd;
	v_this->v_add_to_write = false;
	return (true);
}

void	f_fdnotify_cell_add_to_write(t_fdnotify_cell *v_this)
{
	v_this->v_add_to_write = true;
}

void	f_fdnotify_cell_destroy(t_fdnotify_cell *v_this, bool close_fd)
{
	if (close_fd == true)
		close(v_this->v_fd);
}
