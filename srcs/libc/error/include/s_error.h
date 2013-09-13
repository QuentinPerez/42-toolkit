/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_error.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/13 12:25:09 by qperez            #+#    #+#             */
/*   Updated: 2013/09/13 15:03:07 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains all error prototype>
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

#ifndef S_ERROR_H
# define S_ERROR_H

#include <d_bool.h>

typedef struct	s_error
{
	int	v_fd;
}				t_error;

# define D_ERROR(funct)			f_error_##funct
# define D_PT_TIME(v)			fm_pt_time(v, __DATE__, __TIME__, __FILE__)
# define D_PT_FUNC(v)			fm_pt_funct(v, __LINE__, __func__)
# define D_PT_S_ERR(v, n)		fm_pt_serr(v, D_PT_TIME(v), D_PT_FUNC(v), n)
# define f_error_add(v, n, ret)	fm_error_add(D_PT_S_ERR(v, n), ret)
# define f_error_add_v(v, n)	fm_error_add_v(D_PT_S_ERR(v, n))

bool	f_error_init(t_error *v_this, const char *filename);
void	f_error_destroy(t_error *v_this);
bool	fm_error_add(char nothing, bool ret_val);
void	fm_error_add_v(char nothing);
char	fm_pt_time(t_error *v_this, const char *date, const char *time,
				   const char *file);
char	fm_pt_funct(t_error *v_this, const int line, const char *func);
char	fm_pt_serr(t_error *v_this, char n1, char n2, const char *error);

#endif
