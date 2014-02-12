/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_getopt.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/29 18:08:24 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:43:52 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_getopt prototype>
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

#ifndef S_GETOPT_H
# define S_GETOPT_H

# include <stdbool.h>
# include <t_types.h>

typedef struct	s_getopt
{
	char	**v_option;
	char	**v_posibility;
	char	*v_current_argv;
	t_ui	v_current_argc;
	char	*v_next_argv;
	char	**v_argv;
	t_ui	v_argc;
}				t_getopt;

# define D_GETOPT(funct)	f_getopt_##funct

bool		f_getopt_init(t_getopt *v_this, int argc, const char **argv,
						  const char *opt);
bool		f_getopt_option(t_getopt *v_this);
bool		f_getopt_check(const t_getopt *v_this, const char *option);
const char	*f_getopt_params(const t_getopt *v_this);
void		f_getopt_destroy(t_getopt *v_this);

#endif
