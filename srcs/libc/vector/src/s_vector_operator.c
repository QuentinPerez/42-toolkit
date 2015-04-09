/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vector_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/16 20:15:12 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:56:54 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_vector_operator method>
** < foreach, delete >
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

#include <vector/s_vector.h>
#include <f_error/m_error.h>

bool	f_vector_foreach(t_vector *v_this, bool (*funct)(void *))
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v_this->v_size;
	while (i < size)
	{
		if (funct(v_this->v_data[i]) == false)
			return (false);
		i = i + 1;
	}
	return (true);
}

bool	f_vector_delete(t_vector *v_this, void *ptr)
{
	void	*erase;

	erase = D_VECTOR(erase)(v_this, ptr);
	if (erase == NULL)
		return (M_ERROR(false, "Couldn't find pointer"));
	v_this->f_delete(erase);
	return (true);
}
