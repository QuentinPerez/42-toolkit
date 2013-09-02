/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 20:55:51 by qperez            #+#    #+#             */
/*   Updated: 2013/08/30 23:01:05 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains all s_list prototype>
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

#ifndef S_LIST_H
# define S_LIST_H

#include <s_cell.h>
#include <t_types.h>

typedef struct	s_list
{
	t_cell	*v_begin;
	t_cell	*v_end;
	uint	v_size;
	void	(*v_funct_destroy)(void *data);
}				t_list;

# define D_LIST(funct)	f_list_##funct

void	f_list_init(t_list *v_this, void (*v_funct_destroy)(void *data));
bool	f_list_empty(t_list *v_this);
uint	f_list_size(t_list *v_this);
void	f_list_print_addr(t_list *v_this);
bool	f_list_push_back(t_list *v_this, void *data);
void	*f_list_pop_back(t_list *v_this);
bool	f_list_push_front(t_list *v_this, void *data);
void	*f_list_pop_front(t_list *v_this);
bool	f_list_foreach(t_list *v_this, bool (*funct)(void *value));
void	f_list_reverse(t_list *v_this);
void	f_list_clear(t_list *v_this);
void	f_list_destroy(t_list *v_this);

#endif
