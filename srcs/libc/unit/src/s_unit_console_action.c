/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_unit_console_action.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/01 18:11:51 by qperez            #+#    #+#             */
/*   Updated: 2014/01/08 18:30:11 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_unit_console_action function>
** < console_run >
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

#include <unit/s_unit.h>
#include <unit/s_unit_test.h>
#include <unit/s_unit_context.h>
#include <list/s_list.h>
#include <f_string/f_print.h>

void		uf_unit_console_run(t_list *list)
{
	t_list_cell	*cell;
	t_unit_test	*test;

	cell = D_LIST(begin)(list);
	while (cell != NULL)
	{
		test = (t_unit_test*)cell->v_data;
		uf_print_variadic("\trunning test: %e%s%e\t...\t", 37, test->v_name, 0);
		test->f_func(test);
		if (test->v_failed == true)
			uf_print_variadic("%efailed%e\n", 31, 0);
		else
			uf_print_variadic("%epassed%e\n", 32, 0);
		cell = cell->v_next;
	}
}

static void	uf_unit_console_failure_print_info(t_unit_test *t)
{
	t_list_cell		*cell;
	t_unit_assert	*ass;

	if (t->v_tested == true)
	{
		cell = D_LIST(begin)(&t->v_assert);
		if (cell == NULL)
			uf_print_variadic("\ttest: %e%s%e\t\t   V%e\n",
							37, t->v_name, 32, 0);
		while (cell != NULL)
		{
			ass = (t_unit_assert *)cell->v_data;
			uf_print_variadic("\ttest: %e%s\t\t   %eX\033[0m\t   %s\t\t %d\n",
							37, t->v_name, 31, ass->v_file, ass->v_line);
			cell = cell->v_next;
		}
	}
	else
		uf_print_variadic("\ttest: %e%s%e\t\tUntested%e\n",
						37, t->v_name, 31, 0);
}

void		uf_unit_console_failure(t_list *list)
{
	t_unit_test	*t;
	t_list_cell	*cell;

	cell = D_LIST(begin)(list);
	while (cell != NULL)
	{
		t = (t_unit_test*)cell->v_data;
		uf_unit_console_failure_print_info(t);
		cell = cell->v_next;
	}
}
