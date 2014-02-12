/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_htable_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/08 19:59:30 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:46:09 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_htable_print function>
** < print >
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

#include <htable/s_htable.h>
#include <f_string/f_print.h>
#include <list/s_list.h>

void	f_htable_print(t_htable *v_this, bool (*uf_print)(t_htable_cell *data))
{
	t_ui	i;
	t_list	*list;

	i = 0;
	list = D_ARRAY(data)(&v_this->v_array, t_list *);
	while (i < v_this->v_prime)
	{
		if (D_LIST(size)(list + i) > 0)
		{
			uf_print_char('[');
			uf_print_nbr(i);
			uf_print_str("]-> ");
			D_LIST(foreach)(list + i, (bool (*)(void *))uf_print);
			uf_print_char('\n');
		}
		i = i + 1;
	}
}
