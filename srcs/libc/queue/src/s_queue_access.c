/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_queue_access.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/30 13:26:50 by qperez            #+#    #+#             */
/*   Updated: 2013/09/30 14:26:02 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_queue function>
** < empty, size, front, back >
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

#include <s_queue.h>
#include <stddef.h>

inline bool	f_queue_empty(t_queue *v_this)
{
	return (v_this->v_size == 0);
}

inline ui	f_queue_size(t_queue *v_this)
{
	return (v_this->v_size);
}

inline void	*f_queue_front(t_queue *v_this)
{
	if (v_this->v_head != NULL)
		return (v_this->v_head->v_data);
	return (NULL);
}

inline void	*f_queue_back(t_queue *v_this)
{
	if (v_this->v_tail != NULL)
		return (v_this->v_tail->v_data);
	return (NULL);
}
