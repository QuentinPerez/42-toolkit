/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_cell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 20:58:10 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:44:40 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_list_cell prototype>
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

#ifndef S_LIST_CELL_H
# define S_LIST_CELL_H

# include <stddef.h>

typedef struct	s_list_cell
{
	struct s_list_cell	*v_next;
	struct s_list_cell	*v_prev;
	void				*v_data;
}				t_list_cell;

# define D_LIST_CELL(funct)	f_list_cell_##funct

size_t		f_list_cell_count(const t_list_cell *other_begin,
							  const t_list_cell *other_end);
t_list_cell	*f_list_cell_next(const t_list_cell *cur);
t_list_cell	*f_list_cell_prev(const t_list_cell *cur);

#endif
