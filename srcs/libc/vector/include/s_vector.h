/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vector.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/16 12:11:43 by qperez            #+#    #+#             */
/*   Updated: 2013/09/25 14:44:50 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains all s_vector prototype>
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

#ifndef S_VECTOR_H
# define S_VECTOR_H

#include <t_types.h>
#include <d_bool.h>

typedef struct	s_vector
{
	uint	v_size;
	uint	v_capacity;
	void	**v_data;
	uint	(*f_realloc)(uint size);
	void	(*f_delete)(void *ptr);
}				t_vector;

# define D_VECTOR(funct)	f_vector_##funct

bool	f_vector_init(t_vector *v_this, uint (*uf_realloc)(uint size),
					  void (*uf_delete)(void *ptr));
void	f_vector_clear(t_vector *v_this);
bool	f_vector_empty(const t_vector *v_this);
uint	f_vector_size(const t_vector *v_this);
uint	f_vector_capacity(const t_vector *v_this);
bool	f_vector_push_back(t_vector *v_this, void *data);
void	*f_vector_erase(t_vector *v_this, void *erase);
bool	f_vector_foreach(t_vector *v_this, bool (*funct)(void *ptr));
bool	f_vector_reserve(t_vector *v_this, uint new_size);
void	f_vector_destroy(t_vector *v_this);

#endif
