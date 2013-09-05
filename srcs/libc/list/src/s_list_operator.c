/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/30 22:50:59 by qperez            #+#    #+#             */
/*   Updated: 2013/09/05 14:31:24 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This function contains all s_list_operator method>
** < foreach, reverse, remove >
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

bool	f_list_foreach(t_list *v_this, bool (*funct)(void *data))
{
	t_cell	*cur;

	cur = v_this->v_begin;
	while (cur != NULL)
	{
		if (funct(cur->v_data) == false)
			return (false);
		cur = cur->v_next;
	}
	return (true);
}

void	f_list_reverse(t_list *v_this)
{
	t_cell	*begin;
	t_cell	*end;
	void	*tmp;

	begin = v_this->v_begin;
	end = v_this->v_end;
	while (begin != end)
	{
		tmp = begin->v_data;
		begin->v_data = end->v_data;
		end->v_data = tmp;
		if (end->v_prev == begin)
			break;
		begin = begin->v_next;
		end = end->v_prev;
	}
}

void	f_list_remove(t_list *v_this,
					  bool (*cmp)(void *data, void *value), void *value)
{
	t_cell	*cur;

	cur = v_this->v_begin;
	while (cur != NULL)
	{
		if (cmp(cur->v_data, value) == true)
			cur = D_LIST(erase)(v_this, cur);	
		else
			cur = cur->v_next;
	}
}
