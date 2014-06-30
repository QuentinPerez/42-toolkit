/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_queue.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/30 11:02:36 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:49:37 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_queue prototype>
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

#ifndef S_QUEUE_H
# define S_QUEUE_H

# include <stddef.h>
# include <stdbool.h>

typedef struct	s_queue_cell
{
	void				*v_data;
	struct s_queue_cell	*v_next;
}				t_queue_cell;

typedef struct	s_queue
{
	size_t				v_size;
	t_queue_cell		*v_head;
	t_queue_cell		*v_tail;
	void				(*f_destroy)(void *data);
}				t_queue;

# define D_QUEUE(funct)	f_queue_##funct

void	f_queue_init(t_queue *v_this, void (*funct_destroy)(void *data));
void	f_queue_clear(t_queue *v_this);
void	f_queue_destroy(t_queue *v_this);
bool	f_queue_empty(const t_queue *v_this);
size_t	f_queue_size(const t_queue *v_this);
bool	f_queue_push(t_queue *v_this, void *data);
void	*f_queue_pop(t_queue *v_this);
void	*f_queue_front(t_queue *v_this);
void	*f_queue_back(t_queue *v_this);
bool	f_queue_foreach(t_queue *v_this, bool (*funct)(void * data));

#endif
