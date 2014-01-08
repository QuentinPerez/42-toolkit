/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_unit_console_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/31 13:43:01 by qperez            #+#    #+#             */
/*   Updated: 2014/01/08 18:27:52 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_unit_console_print function>
** < print_main_console >
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

#include <unit/s_unit.h>
#include <unit/s_unit_context.h>
#include <f_string/f_str_tools.h>
#include <f_string/f_print.h>

void	uf_unit_print_nchar(ui size, char c)
{
	ui	i;

	i = 0;
	while (i < size)
	{
		uf_print_char(c);
		i = i + 1;
	}
}

void	uf_unit_print_console(t_unit *v_this, const char *info,
							bool menu, char c)
{
	ui	tmp;

	uf_print_char('\n');
	tmp = (v_this->v_params.v_width >> 1) - (uf_str_len(info) >> 1) - 1;
	uf_unit_print_nchar(tmp, c);
	uf_print_variadic(" %e%s%e ", 34, info, 0);
	uf_unit_print_nchar(tmp, c);
	uf_print_char('\n');
	if (menu == true)
		uf_print_variadic("  (%eR%e)un       (%eS%e)elect       (%eL%e)ist     "
						"  (%eF%e)ailures       (%eH%e)elp       (%eQ%e)uit"
						"\n\n%e↳%e ",
						34, 0, 34, 0, 34, 0, 34, 0, 34, 0, 34, 0, 35, 0);
}

bool	uf_unit_print_context(void *data)
{
	t_unit_context	*context;

	context = (t_unit_context *)data;
	uf_print_variadic("%d\t%e%s%e", context->v_id, 34, context->v_name, 0);
	uf_unit_print_nchar(49 - uf_str_len(context->v_name), ' ');
	if (context->f_init != NULL)
		uf_print_variadic("%eYes\t", 32);
	else
		uf_print_variadic("%e No\t", 31);
	if (context->f_destroy != NULL)
		uf_print_variadic("%eYes\t%E ", 32, 37);
	else
		uf_print_variadic("%e  No\t%e ", 31, 37);
	uf_print_nbr(D_LIST(size)(&context->v_test));
	uf_print_str("\n\033[0m");
	return (true);
}
