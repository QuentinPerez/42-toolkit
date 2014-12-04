/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_fdnotify_cell.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 09:41:04 by qperez            #+#    #+#             */
/*   Updated: 2014/12/04 10:02:54 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains fdnotify_cell prototype>
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

#ifndef S_FDNOTIFY_CELL_H
# define S_FDNOTIFY_CELL_H

# include <stdbool.h>

typedef struct s_fdnotify_cell
{
	int		v_fd;
	bool	v_add_to_write;
}				t_fdnotify_cell;

# define D_FDNOTIFY_CELL(funct)	f_fdnotify_cell_##funct

bool	f_fdnotify_cell_init(t_fdnotify_cell *v_this, int fd);
void	f_fdnotify_cell_add_to_write(t_fdnotify_cell *v_this);
void	f_fdnotify_cell_destroy(t_fdnotify_cell *v_this, bool close_fd);

#endif
