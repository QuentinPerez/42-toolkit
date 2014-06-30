/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_unit_console.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/31 11:39:40 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:55:15 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_unit_console function>
** < console_run >
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

#include <stdlib.h>
#include <unit/s_unit.h>
#include <unit/s_unit_console.h>
#include <f_string/f_string.h>
#include <f_string/f_print.h>

void		uf_unit_console_treat_failure(t_unit *v_this);
void		uf_unit_console_treat_help(t_unit *v_this);
void		uf_unit_console_treat_list(t_unit *v_this);
void		uf_unit_console_treat_run(t_unit *v_this);
void		uf_unit_console_treat_select(t_unit *v_this);
void		uf_unit_print_console(t_unit *v_this, const char *info,
								bool menu, char c);

static void	uf_treat_line(t_unit *v_this, t_unit_console_option *opt, char *str)
{
	size_t	i;

	i = 0;
	while (i < D_UNIT_CONSOLE_OPTION)
	{
		if (uf_str_case_cmp(opt[i].v_option, str) == 0)
		{
			opt[i].f_funct(v_this);
			break ;
		}
		i = i + 1;
	}
	if (i == D_UNIT_CONSOLE_OPTION)
		uf_print_variadic("command not found: %s\n", str);
	free(str);
}

static void	uf_unit_add_option(t_unit_console_option *option, const char *full,
							const char *shortcut, void (*funct)(t_unit *))
{
	static size_t	i = 0;

	option[i].v_option = full;
	option[i].f_funct = funct;
	option[i + 1].v_option = shortcut;
	option[i + 1].f_funct = funct;
	i = i + 2;
}

static void	uf_unit_console_treat_quit(t_unit *v_this)
{
	uf_unit_print_console(v_this, "Good bye", false, ' ');
	v_this->v_params.v_run = false;
}

void		f_unit_console_run(t_unit *v_this)
{
	char					*line;
	t_unit_console_option	opt[D_UNIT_CONSOLE_OPTION];

	uf_unit_add_option(opt, "run", "r", uf_unit_console_treat_run);
	uf_unit_add_option(opt, "quit", "q", uf_unit_console_treat_quit);
	uf_unit_add_option(opt, "select", "s", uf_unit_console_treat_select);
	uf_unit_add_option(opt, "list", "l", uf_unit_console_treat_list);
	uf_unit_add_option(opt, "help", "h", uf_unit_console_treat_help);
	uf_unit_add_option(opt, "failure", "f", uf_unit_console_treat_failure);
	while (v_this->v_params.v_run == true)
	{
		uf_unit_print_console(v_this, "42 Unit testing", true, ' ');
		line = uf_getline(0, true);
		if (line != NULL)
			uf_treat_line(v_this, opt, line);
	}
}
