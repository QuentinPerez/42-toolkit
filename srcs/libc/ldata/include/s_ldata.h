/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ldata.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/05 11:30:57 by qperez            #+#    #+#             */
/*   Updated: 2014/10/05 13:36:31 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains ldata prototype>
** Copyright (C) <2015>  Quentin Perez <qperez42@gmail.com>
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

#ifndef S_LDATA_H
# define S_LDATA_H

# include <stdbool.h>
# include <stddef.h>

typedef struct	s_ldata
{
	void	*v_ptr;
	size_t	v_len;
}				t_ldata;

# define D_LDATA(funct)	f_ldata_##funct

bool	f_ldata_init(t_ldata *v_this, size_t len);
void	*f_ldata_get_ptr(t_ldata *v_this);
void	f_ldata_destroy(t_ldata *v_this);

#endif
