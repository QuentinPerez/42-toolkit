/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rbtree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/13 15:09:23 by qperez            #+#    #+#             */
/*   Updated: 2013/12/29 15:51:40 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_rbtree function>
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

#include <stdlib.h>
#include <rbtree/s_rbtree.h>
#include <f_error/m_error.h>
#include <f_memory/f_memory.h>

static void	uf_rbtree_delete(void *data)
{
	(void)data;
}

bool		f_rbtree_init(t_rbtree *v_this, int (*f_cmp)(void *d1, void *d2),
						  void (*f_del)(void *data))
{
	uf_memset(v_this, 0, sizeof(*v_this));
	if (f_cmp == NULL)
		return (M_ERROR(false, "f_cmp couldn't NULL"));
	v_this->f_delete = uf_rbtree_delete;
	if (f_del != NULL)
		v_this->f_delete = f_del;
	v_this->f_cmp = f_cmp;
	v_this->v_nil.v_left = &v_this->v_nil;
	v_this->v_nil.v_right = &v_this->v_nil;
	v_this->v_nil.v_parent = &v_this->v_nil;
	v_this->v_nil.v_color = e_black;
	v_this->v_root.v_left = &v_this->v_nil;
	v_this->v_root.v_right = &v_this->v_nil;
	v_this->v_root.v_parent = &v_this->v_nil;
	v_this->v_root.v_color = e_black;
	return (true);
}

static void	uf_rbtree_recursive_destroy(t_rbtree *v_this, t_rbcell *node)
{
	if (node != &v_this->v_nil)
	{
		uf_rbtree_recursive_destroy(v_this, node->v_left);
		uf_rbtree_recursive_destroy(v_this, node->v_right);
		v_this->f_delete(node->v_data);
		free(node);
	}
}

void		f_rbtree_destroy(t_rbtree *v_this)
{
	uf_rbtree_recursive_destroy(v_this, v_this->v_root.v_left);
}
