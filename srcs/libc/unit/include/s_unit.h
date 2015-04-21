/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_unit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/31 11:09:07 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:54:07 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_unit prototype>
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

#ifndef S_UNIT_H
# define S_UNIT_H

# include <stdbool.h>
# include <list/s_list.h>
# include <unit/s_unit_params.h>

struct s_unit_test;

typedef struct		s_unit
{
	t_unit_params	v_params;
	t_list			v_context;
}					t_unit;

# define D_UNIT(funct)				f_unit_##funct
# define D_UNIT_FUNCT(name)			tf_##name(struct s_unit_test *t)
# define F_UNIT_ADD_TEST(v, c, n)	mf_unit_add_test(v, c, #n, tf_##n)
# define F_UNIT_ASSERT(check)		mf_unit_assert(t, check, __LINE__, __FILE__)

bool				f_unit_init(t_unit *v_this);
bool				f_unit_add_context(t_unit *v_this, const char *name,
									bool (*init)(void *data),
									bool (*destroy)(void *data));
bool				mf_unit_add_test(t_unit *v_this, const char *context,
									const char *name,
									void (*test)(struct s_unit_test *));
void				mf_unit_assert(struct s_unit_test *t, bool check,
									size_t lin, char *file);
void				f_unit_console_run(t_unit *v_this);
void				f_unit_destroy(t_unit *v_this);

#endif
