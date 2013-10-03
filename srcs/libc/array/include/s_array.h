/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_array.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/02 12:55:27 by qperez            #+#    #+#             */
/*   Updated: 2013/10/03 16:12:50 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains all s_array prototype>
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

#ifndef S_ARRAY_H
# define S_ARRAY_H

#include <t_types.h>
#include <d_bool.h>

typedef struct	s_array
{
	ui		v_size;
	ui		v_type_size;
	ui		v_capacity;
	void	*v_data;
	ui		(*f_realloc)(ui size);
	void	(*f_delete)(void *ptr);
}				t_array;

# define f_array_data(v, type)	(type)fm_array_data(v)
# define D_ARRAY(funct)			f_array_##funct

bool	f_array_init(t_array *v_this, ui (*uf_realloc)(ui size),
					 void (*uf_delete)(void *ptr), ui type_size);
void	f_array_clear(t_array *v_this);
bool	f_array_foreach(t_array *v_this, bool (*funct)(void *data));
bool	f_array_push_back(t_array *v_this, void *data);
bool	f_array_empty(const t_array *v_this);
ui		f_array_capacity(const t_array *v_this);
ui		f_array_size(const t_array *v_this);
void	f_array_remove_if(t_array *v_this, bool (*ft_cmp)(void *d1, void *d2),
						  void *data);
void	f_array_destroy(t_array *v_this);
void	*fm_array_data(t_array *v_this);

#endif
