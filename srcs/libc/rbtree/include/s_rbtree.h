/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rbtree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/13 15:01:54 by qperez            #+#    #+#             */
/*   Updated: 2014/01/08 12:28:21 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_rbtree prototype>
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

#ifndef S_RBTREE_H
# define S_RBTREE_H

# include <stdbool.h>

enum	e_rbcolor
{
	e_red,
	e_black
};

typedef struct	s_rbcell
{
	struct s_rbcell	*v_left;
	struct s_rbcell	*v_right;
	struct s_rbcell	*v_parent;
	void			*v_data;
	enum e_rbcolor	v_color;
}				t_rbcell;

typedef struct	s_rbtree
{
	t_rbcell	v_root;
	t_rbcell	v_nil;
	int			(*f_cmp)(void *d1, void *d2);
	void		(*f_delete)(void *data);
}				t_rbtree;

# define f_rbtree_foreach_pre(v, f, d)	mf_preorder(v, (v)->v_root.v_left, d, f)
# define f_rbtree_foreach_in(v, f, d)	mf_inorder(v, (v)->v_root.v_left, d, f)
# define f_rbtree_foreach_post(v, f, d)	mf_pstorder(v, (v)->v_root.v_left, d, f)
# define D_RBTREE(funct)				f_rbtree_##funct

bool		f_rbtree_init(t_rbtree *v_this, int (*f_cmp)(void *d1, void *d2),
						  void (*f_del)(void *data));
t_rbcell	*f_rbtree_find(t_rbtree *v_this, void *find);
t_rbcell	*f_rbtree_root(t_rbtree *v_this);
bool		f_rbtree_empty(const t_rbtree *v_this);
bool		mf_preorder(t_rbtree *v_this, t_rbcell *node, void *data,
						bool (*funct)(void *node, void *data));
bool		mf_inorder(t_rbtree *v_this, t_rbcell *node, void *data,
					   bool (*funct)(void *node, void *data));
bool		mf_pstorder(t_rbtree *v_this, t_rbcell *node, void *data,
						bool (*funct)(void *node, void *data));
bool		f_rbtree_insert(t_rbtree *v_this, void *v_data);
void 		*f_rbtree_erase(t_rbtree *tree, t_rbcell *node);
void 		f_rbtree_delete(t_rbtree *tree, t_rbcell *node);
void		f_rbtree_destroy(t_rbtree *v_this);

#endif
