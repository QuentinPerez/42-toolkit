/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_htable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/08 13:53:57 by qperez            #+#    #+#             */
/*   Updated: 2014/08/27 10:44:06 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_htable function>
** < init, destroy >
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

#include <htable/s_htable.h>
#include <list/s_list.h>
#include <f_error/m_error.h>
#include <f_memory/f_memory.h>

bool	f_htable_init(t_htable *v_this, size_t prime,
				size_t (*f_generate_key)(size_t prime, const char *str),
				void (*f_delete)(void *ptr))
{
	size_t	i;
	t_list	list;

	i = 0;
	if (D_ARRAY(init)(&v_this->v_array, NULL, (void (*)(void *))D_LIST(destroy),
		sizeof(t_list)) == false)
		return (M_ERROR(false, "Could not initialize array"));
	D_LIST(init)(&list, D_HTABLE(delete_cell));
	while (i < prime)
	{
		D_ARRAY(push_back)(&v_this->v_array, &list);
		i = i + 1;
	}
	v_this->v_prime = prime;
	v_this->f_delete = f_delete;
	v_this->f_generate_key = D_HTABLE(generate_key);
	if (f_generate_key != NULL)
		v_this->f_generate_key = f_generate_key;
	return (true);
}

void	f_htable_destroy(t_htable *v_this)
{
	D_ARRAY(destroy)(&v_this->v_array);
	v_this->v_prime = 0;
	v_this->f_delete = NULL;
	v_this->f_generate_key = NULL;
}
