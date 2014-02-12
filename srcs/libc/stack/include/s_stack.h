/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:34:52 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:50:07 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_stack prototype>
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

#ifndef S_STACK_H
# define S_STACK_H

# include <t_types.h>
# include <stdbool.h>

typedef struct	s_stack_cell
{
	void				*v_data;
	struct s_stack_cell	*v_prev;
}				t_stack_cell;

typedef struct	s_stack
{
	t_ui				v_size;
	t_stack_cell		*v_last;
	void				(*f_destroy)(void *data);
}				t_stack;

# define D_STACK(funct)	f_stack_##funct

void	f_stack_init(t_stack *v_this, void (*funct_destroy)(void *data));
void	f_stack_destroy(t_stack *v_this);
bool	f_stack_push(t_stack *v_this, void *data);
void	f_stack_pop(t_stack *v_this);
void	f_stack_clear(t_stack *v_this);
void	*f_stack_top(t_stack *v_this);
bool	f_stack_empty(const t_stack *v_this);
t_ui	f_stack_size(const t_stack *v_this);
bool	f_stack_foreach(t_stack *v_this, bool (*funct)(void *data));

#endif
