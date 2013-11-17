/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rbtree_private.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/14 18:00:33 by qperez            #+#    #+#             */
/*   Updated: 2013/11/15 13:05:59 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_rbtree_private function>
** <  >
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

#include <rbtree/s_rbtree.h>

void	uf_rotate_left(t_rbtree *v_this, t_rbcell *node)
{
	t_rbcell *child;

	child = node->v_right;
	node->v_right = child->v_left;
	if (child->v_left != &v_this->v_nil)
		child->v_left->v_parent = node;
	child->v_parent = node->v_parent;
	if (node == node->v_parent->v_left)
		node->v_parent->v_left = child;
	else
		node->v_parent->v_right = child;
	child->v_left = node;
	node->v_parent = child;
}

void	uf_rotate_right(t_rbtree *v_this, t_rbcell *node)
{
	t_rbcell *child;

	child = node->v_left;
	node->v_left = child->v_right;
	if (child->v_right != &v_this->v_nil)
		child->v_right->v_parent = node;
	child->v_parent = node->v_parent;
	if (node == node->v_parent->v_left)
		node->v_parent->v_left = child;
	else
		node->v_parent->v_right = child;
	child->v_right = node;
	node->v_parent = child;
}

t_rbcell *uf_rb_next(t_rbtree *v_this, t_rbcell *node)
{
	t_rbcell	*ret;

	if ((ret = node->v_right) != &v_this->v_nil)
	{
		while (ret->v_left != &v_this->v_nil)
			ret = ret->v_left;
	}
	else
	{
		for (ret = node->v_parent; node == ret->v_right; ret = ret->v_parent)
			node = ret;
		if (ret == &v_this->v_root)
			ret = &v_this->v_nil;
	}
	return (ret);
}

