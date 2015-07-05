/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_getopt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/29 18:02:55 by qperez            #+#    #+#             */
/*   Updated: 2015/07/04 20:49:03 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_getopt function>
** < init, destroy >
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

#include <getopt/s_getopt.h>
#include <string/s_string.h>
#include <f_error/m_error.h>
#include <f_memory/f_memory.h>
#include <f_memory/f_free.h>
#include <f_string/f_str_tools.h>
#include <f_string/f_string.h>

static bool	uf_getopt_split_posibility(t_getopt *v_this, const char *posibility)
{
	t_string	string;

	if (D_STRING(init)(&string, 0) == false)
		return (M_ERROR(false, "Could not initialize string"));
	if (D_STRING(add_str)(&string, posibility) == false)
	{
		D_STRING(destroy)(&string);
		return (M_ERROR(false, "Could not add [%s]", posibility));
	}
	v_this->v_posibility = D_STRING(split)(&string, ":");
	if (v_this->v_posibility == NULL)
	{
		D_STRING(destroy)(&string);
		return (M_ERROR(false, "Could not split [%s]", posibility));
	}
	D_STRING(destroy)(&string);
	return (true);
}

static bool	uf_fmt_av(t_getopt *v_this, t_string *string,
					bool value, const char *add)
{
	size_t	i;

	i = 0;
	if (value == true)
	{
		while (v_this->v_posibility[i] != NULL)
		{
			if (uf_strcmp(v_this->v_posibility[i], add) == 0)
			{
				if (D_STRING(add_str)(string, add) == false
					|| D_STRING(add_char)(string, ' ') == false)
					return (false);
			}
			i = i + 1;
		}
	}
	return (true);
}

static bool	uf_getopt_init_option(t_getopt *v_this, size_t ac, const char **av)
{
	size_t		i;
	size_t		size;
	t_string	string;

	i = 1;
	if (D_STRING(init)(&string, 0) == false)
		return (M_ERROR(false, "Could not initialize string"));
	while (i < ac)
	{
		size = uf_str_len(av[i]);
		if (uf_fmt_av(v_this, &string, size == 2 && av[i][0] == '-'
			&& av[i][1] != '-', av[i] + 1) == false
			|| uf_fmt_av(v_this, &string, size > 3 && av[i][0] == '-'
			&& av[i][1] == '-' && av[i][2] != '-', av[i] + 2) == false)
			break ;
		i = i + 1;
	}
	if (i == ac)
	{
		v_this->v_option = D_STRING(split)(&string, " ");
		if (v_this->v_option == NULL)
			i = 0;
	}
	D_STRING(destroy)(&string);
	return (i == ac);
}

bool		f_getopt_init(t_getopt *v_this, int argc,
						const char **argv, const char *opt)
{
	uf_memset(v_this, 0, sizeof(*v_this));
	if (argc < 2)
		return (false);
	if (uf_getopt_split_posibility(v_this, opt) == false)
		return (false);
	if (uf_getopt_init_option(v_this, (size_t)argc, argv) == false)
		return (false);
	if (v_this->v_posibility != NULL)
		uf_free_tab((void **)v_this->v_posibility);
	v_this->v_posibility = NULL;
	v_this->v_current_argc = 1;
	v_this->v_argv = argv;
	v_this->v_argc = (size_t)argc;
	return (true);
}

void		f_getopt_destroy(t_getopt *v_this)
{
	if (v_this->v_option != NULL)
		uf_free_tab((void **)v_this->v_option);
	uf_memset(v_this, 0, sizeof(*v_this));
}
