/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:34:44 by qperez            #+#    #+#             */
/*   Updated: 2014/12/02 11:58:29 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_stack function>
** < init, destroy >
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

#include <stack/s_stack.h>
#include <f_memory/f_memory.h>
#include <f_secure/f_secure.h>

static void	uf_stack_funct_destroy(void *data)
{
	(void)data;
}

void		f_stack_init(t_stack *v_this, void (*uf_funct_destroy)(void *data))
{
	uf_memset(v_this, 0, sizeof(*v_this));
	v_this->f_destroy = uf_stack_funct_destroy;
	if (uf_funct_destroy != NULL)
		v_this->f_destroy = uf_funct_destroy;
}

void		f_stack_clear(t_stack *v_this)
{
	t_stack_cell	*del;

	while (v_this->v_last != NULL)
	{
		del = v_this->v_last;
		v_this->f_destroy(v_this->v_last->v_data);
		v_this->v_last = v_this->v_last->v_prev;
		uf_free_s((void **)&del);
	}
	v_this->v_size = 0;
}

void		f_stack_destroy(t_stack *v_this)
{
	D_STACK(clear)(v_this);
	uf_memset(v_this, 0, sizeof(*v_this));
}
