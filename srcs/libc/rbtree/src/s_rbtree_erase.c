/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rbtree_erase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/15 11:36:38 by qperez            #+#    #+#             */
/*   Updated: 2014/12/02 12:03:36 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_rbtree_erase function>
** < erase >
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

#include <f_secure/f_secure.h>
#include <rbtree/s_rbtree.h>

void			uf_rotate_right(t_rbtree *v_this, t_rbcell *node);
void			uf_rotate_left(t_rbtree *v_this, t_rbcell *node);
t_rbcell		*uf_rb_next(t_rbtree *v_this, t_rbcell *node);

static bool		uf_rb_change_node(t_rbtree *v_this, t_rbcell **node,
								t_rbcell **tmp, bool right)
{
	if (right == true)
		*tmp = (*node)->v_parent->v_right;
	else
		*tmp = (*node)->v_parent->v_left;
	if ((*tmp)->v_color == e_red)
	{
		(*tmp)->v_color = e_black;
		(*node)->v_parent->v_color = e_red;
		if (right == true)
			uf_rotate_left(v_this, (*node)->v_parent);
		else
			uf_rotate_right(v_this, (*node)->v_parent);
		*tmp = (*node)->v_parent->v_right;
	}
	if ((*tmp)->v_right->v_color == e_black
		&& (*tmp)->v_left->v_color == e_black)
	{
		(*node) = (*node)->v_parent;
		(*tmp)->v_color = e_red;
		return (true);
	}
	return (false);
}

static t_rbcell	*uf_rb_fix_color(t_rbtree *v_this, t_rbcell *node,
								t_rbcell *tmp, bool right)
{
	if (tmp->v_right->v_color == e_black)
	{
		tmp->v_left->v_color = e_black;
		tmp->v_color = e_red;
		if (right == true)
			uf_rotate_right(v_this, tmp);
		else
			uf_rotate_left(v_this, tmp);
		tmp = node->v_parent->v_right;
	}
	node->v_parent->v_color = e_black;
	tmp->v_color = node->v_parent->v_color;
	tmp->v_right->v_color = e_black;
	if (right == true)
		uf_rotate_left(v_this, node->v_parent);
	else
		uf_rotate_right(v_this, node->v_parent);
	node = v_this->v_root.v_left;
	return (node);
}

static void		uf_rb_fix_node(t_rbtree *v_this, t_rbcell *node)
{
	t_rbcell	*tmp;

	while (node->v_color == e_black && node != v_this->v_root.v_left)
	{
		if (node == node->v_parent->v_left)
		{
			if (uf_rb_change_node(v_this, &node, &tmp, true) == false)
				node = uf_rb_fix_color(v_this, node, tmp, true);
		}
		else
		{
			if (uf_rb_change_node(v_this, &node, &tmp, false) == false)
				node = uf_rb_fix_color(v_this, node, tmp, false);
		}
	}
	node->v_color = e_black;
}

static void	uf_rb_init_node(t_rbtree *v_this, t_rbcell *node,
							t_rbcell **j, t_rbcell **i)
{
	if (node->v_left == &v_this->v_nil || node->v_right == &v_this->v_nil)
		*i = node;
	else
		*i = uf_rb_next(v_this, node);
	if ((*i)->v_left == &v_this->v_nil)
		*j = (*i)->v_right;
	else
		*j = (*i)->v_left;
	if (((*j)->v_parent = (*i)->v_parent) == &v_this->v_root)
		v_this->v_root.v_left = *j;
	else
	{
		if (*i == (*i)->v_parent->v_left)
			(*i)->v_parent->v_left = *j;
		else
			(*i)->v_parent->v_right = *j;
	}
}

void		*f_rbtree_erase(t_rbtree *v_this, t_rbcell *node)
{
	t_rbcell	*j;
	t_rbcell	*i;
	void		*data;

	data = node->v_data;
	uf_rb_init_node(v_this, node, &j, &i);
	if (i->v_color == e_black)
		uf_rb_fix_node(v_this, j);
	if (i != node)
	{
		i->v_parent = node->v_parent;
		i->v_color = node->v_color;
		i->v_left = node->v_left;
		i->v_right = node->v_right;
		node->v_left->v_parent = i;
		node->v_right->v_parent = i;
		if (node == node->v_parent->v_left)
			node->v_parent->v_left = i;
		else
			node->v_parent->v_right = i;
	}
	uf_free_s((void **)&node);
	return (data);
}
