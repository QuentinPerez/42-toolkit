/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_getopt_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/29 23:09:01 by qperez            #+#    #+#             */
/*   Updated: 2014/01/08 18:31:26 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_getopt_access function>
** < option, check, params >
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

#include <getopt/s_getopt.h>
#include <f_string/f_string.h>
#include <f_string/f_str_tools.h>

static bool	uf_getopt_check_option(t_getopt *v_this, const char *check)
{
	ui	i;

	i = 0;
	while (v_this->v_option[i] != NULL)
	{
		if (uf_strcmp(v_this->v_option[i], check) == 0)
		{
			v_this->v_current_argv = v_this->v_option[i];
			v_this->v_current_argc = v_this->v_current_argc + 1;
			if (v_this->v_current_argc < v_this->v_argc)
				v_this->v_next_argv = v_this->v_argv[v_this->v_current_argc];
			else
				v_this->v_next_argv = NULL;
			return (true);
		}
		i = i + 1;
	}
	return (false);
}

bool		f_getopt_option(t_getopt *v_this)
{
	ui		size;
	char	*av;

	while (v_this->v_current_argc < v_this->v_argc)
	{
		av = v_this->v_argv[v_this->v_current_argc];
		size = uf_str_len(av);
		if (size == 2 && av[0] == '-' && av[1] != '-'
			&& uf_getopt_check_option(v_this, av + 1) == true)
			return (true);;
		if (size > 3 && av[0] == '-' && av[1] == '-' && av[2] != '-'
			&& uf_getopt_check_option(v_this, av + 2) == true)
			return (true); ;
		v_this->v_current_argc = v_this->v_current_argc + 1;
	}
	return (false);
}

bool		f_getopt_check(const t_getopt *v_this, const char *option)
{
	return (uf_strcmp(v_this->v_current_argv, option) == 0);
}

const char	*f_getopt_params(const t_getopt *v_this)
{
	return (v_this->v_next_argv);
}
