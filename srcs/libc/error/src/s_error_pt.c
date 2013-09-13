/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_error_pt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/13 15:07:15 by qperez            #+#    #+#             */
/*   Updated: 2013/09/13 15:10:43 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains error macros method>
** < fm_pt_serr, fm_pt_time, fm_pt_funct >
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

#include <s_error.h>
#include <f_print_fd.h>

char	fm_pt_serr(t_error *v_this, char n1, char n2, const char *error)
{
	uf_print_str_fd("()\n\t\t→ ", v_this->v_fd);
	uf_print_str_fd(error, v_this->v_fd);
	uf_print_char_fd('\n', v_this->v_fd);
	(void)n1;
	(void)n2;
	return (1);
}


char	fm_pt_time(t_error *v_this, const char *date,
				   const char *time, const char *file)
{
	uf_print_char_fd('[', v_this->v_fd);
	uf_print_str_fd(date, v_this->v_fd);
	uf_print_str_fd("] (", v_this->v_fd);
	uf_print_str_fd(time, v_this->v_fd);
	uf_print_str_fd(") ", v_this->v_fd);
	uf_print_str_fd(file, v_this->v_fd);
	uf_print_str_fd(", line ", v_this->v_fd);
	return (1);
}

char	fm_pt_funct(t_error *v_this, const int line, const char *funct)
{
	uf_print_nbr_fd(line, v_this->v_fd);
	uf_print_str_fd(": ", v_this->v_fd);
	uf_print_str_fd(funct, v_this->v_fd);
	return (1);
}

