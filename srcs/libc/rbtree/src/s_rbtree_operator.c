/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rbtree_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/13 18:07:40 by qperez            #+#    #+#             */
/*   Updated: 2014/01/08 18:25:03 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_rbtree_operator function>
** < find, preorder, inorder, postoder >
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

#include <stddef.h>
#include <rbtree/s_rbtree.h>

t_rbcell	*f_rbtree_find(t_rbtree *v_this, void *find)
{
	int			ret;
	t_rbcell	*node;

	node = v_this->v_root.v_left;
	while (node != &v_this->v_nil)
	{
		ret = v_this->f_cmp(find, node->v_data);
		if (ret == 0)
			return (node);
		else if (ret < 0)
			node = node->v_left;
		else
			node = node->v_right;
	}
	return (NULL);
}

bool		mf_preorder(t_rbtree *v_this, t_rbcell *node, void *data,
						bool (*funct)(void *node, void *data))
{
	if (node != &v_this->v_nil)
	{
		if (funct(node->v_data, data) == false)
			return (false);
		if (mf_preorder(v_this, node->v_left, data, funct) == false)
			return (false);
		if (mf_preorder(v_this, node->v_right, data, funct) == false)
			return (false);
	}
	return (true);
}

bool		mf_inorder(t_rbtree *v_this, t_rbcell *node, void *data,
					bool (*funct)(void *node, void *data))
{
	if (node != &v_this->v_nil)
	{
		if (mf_inorder(v_this, node->v_left, data, funct) == false)
			return (false);
		if (funct(node->v_data, data) == false)
			return (false);
		if (mf_inorder(v_this, node->v_right, data, funct) == false)
			return (false);
	}
	return (true);
}

bool		mf_pstorder(t_rbtree *v_this, t_rbcell *node, void *data,
						bool (*funct)(void *node, void *data))
{
	if (node != &v_this->v_nil)
	{
		if (mf_pstorder(v_this, node->v_left, data, funct) == false)
			return (false);
		if (mf_pstorder(v_this, node->v_right, data, funct) == false)
			return (false);
		if (funct(node->v_data, data) == false)
			return (false);
	}
	return (true);
}
