/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_queue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/30 11:02:29 by qperez            #+#    #+#             */
/*   Updated: 2014/12/02 11:57:37 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_queue function>
** < init, destroy, clear >
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

#include <queue/s_queue.h>
#include <f_memory/f_memory.h>
#include <f_secure/f_secure.h>

static void	uf_queue_funct_destroy(void *data)
{
	(void)data;
}

void		f_queue_init(t_queue *v_this, void (*uf_funct_destroy)(void *data))
{
	v_this->v_size = 0;
	v_this->v_head = NULL;
	v_this->v_tail = NULL;
	v_this->f_destroy = uf_queue_funct_destroy;
	if (uf_funct_destroy != NULL)
		v_this->f_destroy = uf_funct_destroy;
}

void		f_queue_clear(t_queue *v_this)
{
	t_queue_cell	*del;

	while (v_this->v_head != NULL)
	{
		del = v_this->v_head;
		v_this->f_destroy(del->v_data);
		v_this->v_head = del->v_next;
		uf_free_s((void **)&del);
	}
	v_this->v_tail = NULL;
	v_this->v_head = NULL;
	v_this->v_size = 0;
}

void		f_queue_destroy(t_queue *v_this)
{
	D_QUEUE(clear)(v_this);
	v_this->v_size = 0;
	v_this->v_head = NULL;
	v_this->v_tail = NULL;
	v_this->f_destroy = NULL;
}
