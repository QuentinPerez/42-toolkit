/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rbtree_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/13 19:17:19 by qperez            #+#    #+#             */
/*   Updated: 2014/12/02 11:27:09 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_rbtree_insert function>
** < insert >
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

#include <rbtree/s_rbtree.h>
#include <f_error/m_error.h>
#include <f_secure/f_secure.h>

void			uf_rotate_right(t_rbtree *v_this, t_rbcell *node);
void			uf_rotate_left(t_rbtree *v_this, t_rbcell *node);

static t_rbcell	*uf_rb_balance_rot(t_rbtree *v_this, t_rbcell *node,
								bool check, bool right)
{
	if (check == true)
	{
		node = node->v_parent;
		if (right == true)
			uf_rotate_left(v_this, node);
		else
			uf_rotate_right(v_this, node);
	}
	node->v_parent->v_color = e_black;
	node->v_parent->v_parent->v_color = e_red;
	if (right == true)
		uf_rotate_right(v_this, node->v_parent->v_parent);
	else
		uf_rotate_left(v_this, node->v_parent->v_parent);
	return (node);
}

static t_rbcell	*uf_rb_balance(t_rbtree *v_this, t_rbcell *node,
							bool check, bool right)
{
	t_rbcell *uncle;

	if (right == true)
		uncle = node->v_parent->v_parent->v_right;
	else
		uncle = node->v_parent->v_parent->v_left;
	if (uncle->v_color == e_red)
	{
		node->v_parent->v_color = e_black;
		uncle->v_color = e_black;
		node->v_parent->v_parent->v_color = e_red;
		node = node->v_parent->v_parent;
	}
	else
		uf_rb_balance_rot(v_this, node, check, right);
	return (node);
}

static t_rbcell	*uf_rb_node_exist(t_rbtree *v_this, t_rbcell **parent, void *d)
{
	t_rbcell	*node;
	int			res;

	node = v_this->v_root.v_left;
	*parent = &v_this->v_root;
	while (node != &v_this->v_nil)
	{
		*parent = node;
		res = v_this->f_cmp(d, node->v_data);
		if (res == 0)
			return (NULL);
		if (res < 0)
			node = node->v_left;
		else
			node = node->v_right;
	}
	if ((node = uf_malloc_s(1, sizeof(*node))) == NULL)
		return ((t_rbcell *)M_ERROR(0, "Bad alloc"));
	node->v_data = d;
	node->v_left = node->v_right = &v_this->v_nil;
	node->v_parent = *parent;
	return (node);
}

bool				f_rbtree_insert(t_rbtree *v_this, void *data)
{
	t_rbcell	*n;
	t_rbcell	*parent;

	n = uf_rb_node_exist(v_this, &parent, data);
	if (n == NULL)
		return (false);
	if (parent == &v_this->v_root || v_this->f_cmp(data, parent->v_data) < 0)
		parent->v_left = n;
	else
		parent->v_right = n;
	n->v_color = e_red;
	while (n->v_parent->v_color == e_red)
	{
		if (n->v_parent == n->v_parent->v_parent->v_left)
			n = uf_rb_balance(v_this, n, n == n->v_parent->v_right, true);
		else
			n = uf_rb_balance(v_this, n, n == n->v_parent->v_left, false);
	}
	v_this->v_root.v_left->v_color = e_black;
	return (true);
}
