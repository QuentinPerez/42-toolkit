/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_splice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/07 04:18:37 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/12 19:47:48 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_list_splice method>
** < splice >
** Copyright (C) <2013>  Iohann Rabeson <irabeson42@gmail.com>
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

#include <list/s_list.h>
#include <f_error/m_error.h>

static void	f_list_pick_cells_imp(t_list *const v_this,
								t_list_cell *const begin,
								t_list_cell *const end)
{
	t_list_cell	*cell_before;
	t_list_cell	*cell_after;

	cell_before = D_LIST_CELL(prev)(begin);
	cell_after = D_LIST_CELL(next)(end);
	if (cell_before == NULL)
	{
		v_this->v_begin = cell_after;
		if (cell_after != NULL)
			cell_after->v_prev = NULL;
	}
	else
		cell_before->v_next = cell_after;
	if (cell_after == NULL)
	{
		if (D_LIST(begin)(v_this) != NULL)
			v_this->v_end = D_LIST_CELL(next)(v_this->v_begin);
		else
			v_this->v_end = D_LIST(begin)(v_this);
	}
	else
		cell_after->v_prev = cell_before;
}

static size_t	f_list_pick_cells(t_list *const v_this, t_list_cell *const begin,
							t_list_cell *end)
{
	size_t	cell_count;

	if (D_LIST(empty)(v_this) == true)
		return (0);
	if (end == NULL)
		end = D_LIST(end)(v_this);
	cell_count = D_LIST_CELL(count)(begin, end);
	D_LIST(pick_cells_imp)(v_this, begin, end);
	v_this->v_size = D_LIST(size)(v_this) - cell_count;
	begin->v_prev = NULL;
	end->v_next = NULL;
	return (cell_count);
}

static void	f_list_splice_imp(t_list *const v_this, t_list_cell *const position,
							t_list_cell *const other_begin,
							t_list_cell *const other_end)
{
	t_list_cell	*before;

	before = D_LIST_CELL(prev)(position);
	if (before == NULL)
	{
		v_this->v_begin = other_begin;
		v_this->v_begin->v_prev = NULL;
	}
	else
	{
		before->v_next = other_begin;
		other_begin->v_prev = before;
	}
	position->v_prev = other_end;
	other_end->v_next = position;
}

void		f_list_splice(t_list *v_this, t_list_cell *position,
						t_list *other_list, t_list_interval *other_interval)
{
	size_t	cell_count;

	cell_count = D_LIST(pick_cells)(other_list,
									D_LIST_INTERVAL(begin)(other_interval),
									D_LIST_INTERVAL(end)(other_interval));
	if (cell_count == 0)
		return ;
	if (D_LIST(empty)(v_this) == true)
	{
		v_this->v_size = cell_count;
		v_this->v_begin = D_LIST_INTERVAL(begin)(other_interval);
		v_this->v_end = D_LIST_INTERVAL(end)(other_interval);
		return ;
	}
	if (position == NULL)
	{
		position = D_LIST(end)(v_this);
		position->v_next = D_LIST_INTERVAL(begin)(other_interval);
		D_LIST_INTERVAL(begin)(other_interval)->v_prev = position;
	}
	else
		D_LIST(splice_imp)(v_this, position,
						D_LIST_INTERVAL(begin)(other_interval),
						D_LIST_INTERVAL(end)(other_interval));
	v_this->v_size = D_LIST(size)(v_this) + cell_count;
}
