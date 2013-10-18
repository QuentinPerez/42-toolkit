/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_htable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/08 13:47:03 by qperez            #+#    #+#             */
/*   Updated: 2013/10/09 12:00:07 by qperez           ###   ########.fr       */
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

#ifndef S_HTABLE_H
# define S_HTABLE_H

#include <array/s_array.h>

typedef struct	s_htable_cell
{
	char	*v_key;
	void	*v_data;
	void	(*f_delete)(void *data);
}				t_htable_cell;

typedef struct	s_htable
{
	t_array	v_array;
	ui		v_prime;
	void	(*f_delete)(void *data);
}				t_htable;

# define D_HTABLE(funct)	f_htable_##funct

bool	f_htable_init(t_htable *v_this, ui size, void (*f_del)(void *ptr));
bool	f_htable_add(t_htable *v_this, const char *key, void *data);
void	*f_htable_get(t_htable *v_this, const char *key);
void	f_htable_print(t_htable *v_this, bool (*uf_print)(t_htable_cell *data));
void	f_htable_delete(t_htable *v_this, const char *key);
void	*f_htable_erase(t_htable *v_this, const char *key);
void	f_htable_destroy(t_htable *v_this);

#endif
