/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_splice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachafroment <sachafroment@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/07 04:18:37 by irabeson          #+#    #+#             */
/*   Updated: 2016/03/02 21:14:21 by sachafroment     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_list_splice method>
** < splice >
** Copyright (C) <2013>  Iohann Rabeson <irabeson42@gmail.com>
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

#include <list/s_list.h>
#include <f_error/m_error.h>

static void		f_list_free_from(t_list_cell *start)
{
	t_list	fake_list;

	D_LIST(init)(&fake_list, 0);
	fake_list.v_begin = start;
	D_LIST(destroy)(&fake_list);
}

static void		f_list_splice_empty(t_list *v_this, t_list_cell *start,
									t_list_cell *end)
{
	t_list_cell	*cur;

	cur = start;
	void (*uf_funct_destroy)(void *) = (void*)START_BLOCK(void, void *data)
	{ return ; } END_BLOCK
	v_this->f_destroy = uf_funct_destroy;
	v_this->v_begin = start;
	v_this->v_end = end;
	while (cur != NULL)
	{
		if (D_LIST(push_back)(v_this, cur->v_data) == false)
		{
			D_LIST(clear)(v_this);
			return ;
		}
		cur = cur->v_next;
	}
	return ;
}

static void		f_list_cell_start_end(t_list *other_list,
									t_list_interval *other_interval,
									t_list_cell **other_start,
									t_list_cell **other_end)
{
	if (other_interval && other_interval->v_begin)
		*other_start = other_interval->v_begin;
	else
		*other_start = D_LIST(begin)(other_list);
	if (other_interval && other_interval->v_end)
		*other_end = other_interval->v_end;
	else
		*other_end = D_LIST(end)(other_list);
}

static size_t	f_list_splice_imp(t_list_cell *my_start,
								t_list_cell *my_end,
								t_list_cell *other_start,
								t_list_cell *other_end)
{
	t_list_cell	*tmp;
	size_t		count;

	tmp = my_start;
	count = 0;
	while (tmp->v_data != other_end->v_data)
	{
		tmp->v_next = D_LIST_CELL(create)(tmp,
			tmp->v_next, other_start->v_data);
		if (!tmp->v_next)
		{
			D_LIST(free_from)(my_start->v_next);
			tmp = my_start;
			count = 0;
			break ;
		}
		other_start = other_start->v_next;
		tmp = tmp->v_next;
		++count;
	}
	tmp->v_next = my_end;
	return (count);
}

void			f_list_splice(t_list *v_this, t_list_cell *position,
							t_list *other_list, t_list_interval *other_interval)
{
	t_list_cell	*my_start;
	t_list_cell	*my_end;
	t_list_cell	*other_start;
	t_list_cell	*other_end;
	size_t		count;

	if (D_LIST(size)(other_list) == 0)
		return ;
	D_LIST_CELL(start_end)
	(other_list, other_interval, &other_start, &other_end);
	if (D_LIST(empty)(v_this) == true)
	{
		D_LIST(splice_empty)(v_this, other_start, other_end);
		return ;
	}
	my_end = NULL;
	if (position == NULL)
		my_start = D_LIST(end)(v_this);
	else
	{
		my_start = D_LIST_CELL(prev)(position);
		my_end = position;
	}
	count = D_LIST(splice_imp)(my_start, my_end, other_start, other_end);
	v_this->v_size = D_LIST(size)(v_this) + count;
}
