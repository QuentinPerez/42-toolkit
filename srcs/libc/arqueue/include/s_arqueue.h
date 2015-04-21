/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_arqueue.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/30 00:36:31 by qperez            #+#    #+#             */
/*   Updated: 2014/07/05 13:33:52 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_arqueue prototype>
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

#ifndef S_ARQUEUE_H
# define S_ARQUEUE_H

# include <stdbool.h>
# include <stddef.h>

typedef struct	s_arqueue
{
	size_t		v_start;
	size_t		v_end;
	size_t		v_size;
	size_t		v_capacity;
	size_t		v_sizeof;
	void		*v_array;
}				t_arqueue;

# define D_ARQUEUE(funct)	f_arqueue_##funct

bool			f_arqueue_init(t_arqueue *v_this, size_t elem_size,
								size_t nb_elem);
bool			f_arqueue_push(t_arqueue *v_this, void *push);
bool			f_arqueue_empty(t_arqueue *v_this);
void			*f_arqueue_pop(t_arqueue *v_this);
void			f_arqueue_destroy(t_arqueue *v_this);

#endif
