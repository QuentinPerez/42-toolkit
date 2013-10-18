/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vector_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/16 20:26:33 by qperez            #+#    #+#             */
/*   Updated: 2013/09/26 13:33:58 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_vector_access method>
** < at, front, back, data >
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

#include <vector/s_vector.h>
#include <stddef.h>

inline void	*f_vector_at(t_vector *v_this, ui index)
{
	if (index > v_this->v_size - 1)
		return (NULL);
	return (v_this->v_data[index]);
}

void	**f_vector_data(t_vector *v_this)
{
	return (v_this->v_data);
}

inline void	*f_vector_front(t_vector *v_this)
{
	if (v_this->v_size > 1)
		return (v_this->v_data[0]);
	return (NULL);
}

inline void	*f_vector_back(t_vector *v_this)
{
	if (v_this->v_size > 1)
		return (v_this->v_data[v_this->v_size - 1]);
	return (NULL);
}
