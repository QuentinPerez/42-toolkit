/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:34:44 by qperez            #+#    #+#             */
/*   Updated: 2013/09/27 17:42:21 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_stack function>
** < init, destroy >
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

#include <s_stack.h>
#include <f_memory.h>
#include <stdlib.h>

static void	f_stack_funct_destroy(void *data)
{
	(void)data;
}

void		f_stack_init(t_stack *v_this, void (*funct_destroy)(void *data))
{
	uf_memset(v_this, 0, sizeof(*v_this));
	v_this->v_funct_destroy = f_stack_funct_destroy;
	if (funct_destroy != NULL)
		v_this->v_funct_destroy = funct_destroy;
}

void		f_stack_clear(t_stack *v_this)
{
	t_stack_cell	*del;

	while (v_this->v_last != NULL)
	{
		del = v_this->v_last;
		v_this->v_funct_destroy(v_this->v_last->v_data);
		v_this->v_last = v_this->v_last->v_prev;
		free(del);
	}
	v_this->v_size = 0;
}

void		f_stack_destroy(t_stack *v_this)
{
	D_STACK(clear)(v_this);
	uf_memset(v_this, 0, sizeof(*v_this));
}
