/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_unit_assert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/31 19:00:08 by qperez            #+#    #+#             */
/*   Updated: 2014/12/02 11:37:44 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_unit_assert function>
** < assert >
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

#include <f_secure/f_secure.h>
#include <list/s_list.h>
#include <unit/s_unit_test.h>
#include <unit/s_unit.h>

void	mf_unit_assert(t_unit_test *t, bool check, size_t line, char *file)
{
	t_unit_assert	*assert;

	if (check == false)
	{
		if ((assert = uf_malloc_s(1, sizeof(*assert))) != NULL)
		{
			assert->v_file = file;
			assert->v_line = line;
			if (D_LIST(push_back)(&t->v_assert, assert) == false)
				uf_free_s((void **)&assert);
			else
				t->v_failed = true;
		}
	}
	t->v_tested = true;
}
