/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_htable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/08 13:53:57 by qperez            #+#    #+#             */
/*   Updated: 2013/10/08 14:39:53 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_htable function>
** < init, destroy >
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

#include <s_htable.h>
#include <s_list.h>
#include <m_error.h>

bool	f_htable_init(t_htable *v_this, ui prime, void (*f_delete)(void *ptr))
{
	ui		i;
	t_list	*list;

	i = 0;
	if (D_ARRAY(init)(&v_this->v_array, NULL, (void (*)(void *))D_LIST(destroy),
					  sizeof(t_list)) == false)
		return (m_error("Could not initialize array", false));
	list = D_ARRAY(data)(&v_this->v_array, t_list *);
	while (i < prime)
	{
		D_LIST(init)(&list[i], f_delete);
		i = i + 1;
	}
	v_this->v_prime = prime;
	return (true);
}

void	f_htable_destroy(t_htable *v_this)
{
	ui		i;
	t_list	*list;

	i = 0;
	list = D_ARRAY(data)(&v_this->v_array, t_list *);
	while (i < v_this->v_prime)
	{
		D_LIST(destroy)(&list[i]);
		i = i + 1;
	}
	D_ARRAY(destroy)(&v_this->v_array);
}
