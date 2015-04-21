/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_error.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/13 12:25:09 by qperez            #+#    #+#             */
/*   Updated: 2014/01/08 12:24:01 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains error prototype>
** Copyright (C) <2013>  Quentin Perez <qperez42@gmail.com>
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

#ifndef S_ERROR_H
# define S_ERROR_H

# include <stdbool.h>

typedef struct	s_error
{
	int			v_fd;
}				t_error;

# define D_ERROR(funct)				f_error_##funct
# define D_MINFOS(v)				mf_pt_infos(v, __LINE__, __func__, __FILE__)
# define F_ERROR_ADD(v, r, f, ...)	mf_add(v, D_MINFOS(v), r, f, ##__VA_ARGS__)

bool			f_error_init(t_error *v_this, const char *filename);
void			f_error_destroy(t_error *v_this);
bool			mf_add(t_error *v_this, char nothing, bool ret,
						const char *error, ...);
char			mf_pt_infos(t_error *v_this, const int line, const char *funct,
					const char *file);

#endif
