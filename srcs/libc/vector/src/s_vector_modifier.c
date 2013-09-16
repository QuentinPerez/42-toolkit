/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vector_modifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/16 15:17:58 by qperez            #+#    #+#             */
/*   Updated: 2013/09/16 15:25:43 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_vector_modifier method>
** < push_back >
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

#include <s_vector.h>
#include <stdlib.h>
#include <m_error.h>

static bool	f_vector_realloc(t_vector *v_this, uint size)
{
	void	**tmp;

	tmp = v_this->v_data;
	v_this->v_data = realloc(v_this->v_data, sizeof(*v_this->v_data) * size);
	if (v_this->v_data == NULL)
	{
		v_this->v_data = tmp;
		return (m_error("Bad alloc", false));
	}
	v_this->v_capacity = size;
	return (true);
}

bool		f_vector_push_back(t_vector *v_this, void *data)
{
	uint	new_size;

	if (data == NULL)
		return (m_error("Null pointer", false));
	new_size = v_this->f_realloc(v_this->v_size);
	if (v_this->v_size + 1 > v_this->v_capacity &&
		D_VECTOR(realloc)(v_this, new_size) == false)
		return (false);
	v_this->v_data[v_this->v_size] = data;
	v_this->v_size = v_this->v_size + 1;
	return (true);
}




