/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_error_pt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/13 15:07:15 by qperez            #+#    #+#             */
/*   Updated: 2013/10/28 13:04:52 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains error macros method>
** < fm_error_infos >
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

#include <time.h>
#include <error/s_error.h>
#include <f_string/f_print_fd.h>

char	fm_pt_infos(t_error *v_this, const int line,
					const char *funct, const char *file)
{
	time_t		raw_time;
	struct tm	*ptm;

	time(&raw_time);
	ptm = gmtime(&raw_time);
	uf_print_str_fd("(", v_this->v_fd);
	uf_print_nbr_fd((ptm->tm_hour + 1) % 24, v_this->v_fd);
	uf_print_str_fd(":", v_this->v_fd);
	uf_print_nbr_fd(ptm->tm_min, v_this->v_fd);
	uf_print_str_fd(":", v_this->v_fd);
	uf_print_nbr_fd(ptm->tm_sec, v_this->v_fd);
	uf_print_str_fd(") ", v_this->v_fd);
	uf_print_str_fd(file, v_this->v_fd);
	uf_print_str_fd(", line ", v_this->v_fd);
	uf_print_nbr_fd(line, v_this->v_fd);
	uf_print_str_fd(": ", v_this->v_fd);
	uf_print_str_fd(funct, v_this->v_fd);
	(void)v_this;
	return (1);
}

