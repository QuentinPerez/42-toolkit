/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/13 12:48:51 by qperez            #+#    #+#             */
/*   Updated: 2013/09/13 15:10:46 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains error method>
** < init, destroy, add, add_v >
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

#include <error/s_error.h>
#include <unistd.h>
#include <fcntl.h>

bool	f_error_init(t_error *v_this, const char *filename)
{
	if (filename == NULL)
	{
		v_this->v_fd = 2;
		return (true);
	}
	v_this->v_fd = open(filename, O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 0644);
	return (v_this->v_fd != -1);
}

bool	fm_error_add(char nothing, bool ret)
{
	(void)nothing;
	return (ret);
}

void	fm_error_add_v(char nothing)
{
	(void)nothing;
}

void	f_error_destroy(t_error *v_this)
{
	if (v_this->v_fd > 2)
		close(v_this->v_fd);
}
