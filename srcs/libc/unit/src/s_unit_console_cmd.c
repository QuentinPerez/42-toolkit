/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_unit_console_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/31 14:21:14 by qperez            #+#    #+#             */
/*   Updated: 2014/01/08 18:27:32 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_unit_console_cmd function>
** < treat_run, treat_select, treat_list, treat_failure, treat_help >
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
#include <unit/s_unit_context.h>
#include <list/s_list.h>
#include <f_string/f_print.h>

bool	uf_unit_print_context(void *data);
void	uf_unit_console_run(t_list *list);
void	uf_unit_console_failure(t_list *list);
void	uf_unit_print_console(t_unit *v_this, const char *info,
							bool menu, char c);

void	uf_unit_console_treat_run(t_unit *v_this)
{
	t_list_cell		*cell;
	t_unit_context	*ctxt;

	cell = D_LIST(begin)(&v_this->v_context);
	uf_unit_print_console(v_this, "Running", false, '-');
	while (cell != NULL)
	{
		ctxt = (t_unit_context*)cell->v_data;
		if (D_LIST(empty)(&ctxt->v_test) == false)
		{
			uf_print_variadic("\nrunning context: %e%s%e\n",
							35, ctxt->v_name, 0);
			uf_unit_console_run(&ctxt->v_test);
		}
		cell = cell->v_next;
	}
	uf_unit_print_console(v_this, "-", false, '-');
}

void	uf_unit_console_treat_select(t_unit *v_this)
{
	uf_print_str(__func__);
	(void)v_this;
}

void	uf_unit_console_treat_list(t_unit *v_this)
{
	uf_unit_print_console(v_this, "Context", false, '-');
	uf_print_str("Id\tName\t\t\t\t\t\t Init\tDestroy\tTest\n\n");
	D_LIST(foreach)(&v_this->v_context, uf_unit_print_context);
	uf_unit_print_console(v_this, "-", false, '-');
	uf_print_char('\n');
}

void	uf_unit_console_treat_failure(t_unit *v_this)
{
	t_list_cell		*cell;
	t_unit_context	*ctxt;

	cell = D_LIST(begin)(&v_this->v_context);
	uf_unit_print_console(v_this, "Failures", false, '-');
	uf_print_str("\t\tName\t\t Statut\t\tFile\t\tLine\n\n");
	while (cell != NULL)
	{
		ctxt = (t_unit_context*)cell->v_data;
		if (D_LIST(empty)(&ctxt->v_test) == false)
		{
			uf_print_variadic("\ncontext: %e%s%e\n",
							35, ctxt->v_name, 0);
			uf_unit_console_failure(&ctxt->v_test);
		}
		cell = cell->v_next;
	}
	uf_unit_print_console(v_this, "-", false, '-');
}

void	uf_unit_console_treat_help(t_unit *v_this)
{
	uf_unit_print_console(v_this, "Help", false, '-');
	uf_print_variadic("\n\t%eR%e - Run all tests in all contexts"
					"\n\t%eS%e - Select context to run"
					"\n\t%eL%e - Show all context"
					"\n\t%eF%e - Show failure from last test"
					"\n\t%eH%e - Show command"
					"\n\t%eQ%e - Quit the program\n",
					34, 0, 34, 0, 34, 0, 34, 0, 34, 0, 34, 0);
	uf_unit_print_console(v_this, "-", false, '-');
}
