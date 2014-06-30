/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_unit_test.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/31 18:18:43 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:54:30 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_unit_test prototype>
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

#ifndef S_UNIT_TEST_H
# define S_UNIT_TEST_H

# include <stdbool.h>
# include <stddef.h>
# include <list/s_list.h>

typedef struct	s_unit_assert
{
	size_t		v_line;
	const char	*v_file;
}				t_unit_assert;

typedef struct	s_unit_test
{
	bool		v_active;
	bool		v_tested;
	bool		v_failed;
	const char	*v_name;
	void		(*f_func)(struct s_unit_test *unit);
	t_list		v_assert;
}				t_unit_test;

#endif
