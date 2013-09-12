/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 20:52:06 by qperez            #+#    #+#             */
/*   Updated: 2013/09/12 13:58:20 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This function contains all s_list method>
** < init, print_addr, clear, destroy >
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

#include <s_list.h>
#include <stddef.h>
#include <f_print.h>
#include <stdlib.h>

static void	f_list_funct_destroy(void *data)
{
	(void)data;
}

void		f_list_init(t_list *v_this, void (*funct_destroy)(void *data))
{
	v_this->v_begin = NULL;
	v_this->v_end = NULL;
	v_this->v_size = 0;
	if (funct_destroy == NULL)
		v_this->v_funct_destroy = funct_destroy;
	else
		v_this->v_funct_destroy = &f_list_funct_destroy;
}

inline void	f_list_print_addr(const t_list *v_this)
{
	t_cell	*current;

	uf_print_str("\033[1;34mBegin\033[0m : ");
	uf_print_addr(v_this->v_begin);
	uf_print_str("\t\t\t\033[1;35mEnd\033[0m : ");
	uf_print_addr(v_this->v_end);
	uf_print_str("\n");
	current = v_this->v_begin;
	while (current != NULL)
	{
		uf_print_addr(current->v_prev);
		if (current->v_prev == NULL)
			uf_print_char('\t');
		uf_print_str("\t<- ");
		uf_print_addr(current);
		uf_print_str(" ->\t");
		uf_print_addr(current->v_next);
		uf_print_str("\n\033[0m");
		current = current->v_next;
	}
}

void		f_list_clear(t_list *v_this)
{
	t_cell	*cur;
	t_cell	*del;

	cur = v_this->v_begin;
	while (cur != NULL)
	{
		del = cur;
		cur = cur->v_next;
		v_this->v_funct_destroy(del->v_data);
		free(del);
	}
	D_LIST(init)(v_this, v_this->v_funct_destroy);
}

void		f_list_destroy(t_list *v_this)
{
	D_LIST(clear)(v_this);
	v_this->v_funct_destroy = NULL;
}
