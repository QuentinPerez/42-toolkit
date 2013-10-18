/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_cell_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/07 19:58:18 by irabeson          #+#    #+#             */
/*   Updated: 2013/10/09 23:38:09 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_list_cell_count method>
** < count >
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

#include <list/s_list_cell.h>
#include <stddef.h>

ui	f_list_cell_count(const t_list_cell *other_begin,
					  const t_list_cell *other_end)
{
	ui	count;

	count = 0;
	if (other_end != NULL)
	{
		while (other_begin != NULL)
		{
			if (other_begin == other_end)
			{
				count = count + 1;
				break;
			}
			count = count + 1;
			other_begin = other_begin->v_next;
		}
	}
	return (count);
}
