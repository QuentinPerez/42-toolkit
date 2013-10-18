/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sort.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/18 12:23:30 by qperez            #+#    #+#             */
/*   Updated: 2013/10/18 12:59:37 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_sort prototype>
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

#ifndef S_SORT_H
# define S_SORT_H

#include <d_bool.h>
#include <t_types.h>

typedef struct	s_sort
{
	ui		v_sizeof;
	bool	(*f_cmp)(void* left, void *right);
	void	(*f_swap)(void* left, void *right);
}				t_sort;

# define D_SORT(funct)	f_sort_##funct

void	f_sort_init(t_sort *v_this, bool (*cmp)(void *d1, void *d2),
					void (*swap)(void *d1, void *d2), ui size_of);
void	f_sort_bubble(t_sort *v_this, void *ptr, ui size);

#endif
