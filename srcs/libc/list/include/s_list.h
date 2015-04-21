/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 20:55:51 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:44:57 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_list prototype>
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

#ifndef S_LIST_H
# define S_LIST_H

# include <stdbool.h>
# include <stddef.h>
# include <list/s_list_cell.h>
# include <list/s_list_interval.h>

typedef struct	s_list
{
	t_list_cell	*v_begin;
	t_list_cell	*v_end;
	size_t		v_size;
	void		(*f_destroy)(void *data);
}				t_list;

# define D_LIST(funct)	f_list_##funct

void			f_list_init(t_list *v_this,
							void (*v_funct_destroy)(void *data));
bool			f_list_empty(const t_list *v_this);
size_t			f_list_size(const t_list *v_this);
t_list_cell		*f_list_begin(const t_list *v_this);
t_list_cell		*f_list_end(const t_list *v_this);
t_list_cell		*f_list_erase(t_list *v_this, t_list_cell *erase, void **data);
t_list_cell		*f_list_get_cell(t_list *list, size_t cell_at);
void			f_list_print_addr(const t_list *v_this);
bool			f_list_push_back(t_list *v_this, void *data);
void			f_list_pop_back(t_list *v_this);
bool			f_list_push_front(t_list *v_this, void *data);
void			f_list_pop_front(t_list *v_this);
t_list_cell		*f_list_insert(t_list *v_this, t_list_cell *position,
							void *data);
t_list_cell		*f_list_find(t_list *v_this, bool (*cmp)(void *, void *),
							void *d);
void			*f_list_back(t_list *v_this);
void			*f_list_front(t_list *v_this);
void			f_list_split(t_list *v_this, t_list_cell *split_at,
						t_list *new_list);
bool			f_list_foreach(t_list *v_this, bool (*funct)(void *value));
void			f_list_reverse(t_list *v_this);
void			f_list_splice(t_list *v_this, t_list_cell *position,
						t_list *other_list, t_list_interval *other_interval);
t_list_cell		*f_list_delete(t_list *v_this, t_list_cell *mb_delete);
void			f_list_delete_if(t_list *v_this,
						bool (*cmp)(void *data, void *value), void *value);
void			f_list_clear(t_list *v_this);
void			f_list_destroy(t_list *v_this);
t_list_cell		*f_list_cell_create(t_list_cell *prv, t_list_cell *nxt,
								void *data);

#endif
