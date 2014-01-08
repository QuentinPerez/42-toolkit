/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_matrix.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmuller <clara.muller19@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/09 19:20:01 by cmuller           #+#    #+#             */
/*   Updated: 2014/01/08 12:27:56 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_matrix prototype>
** Copyright (C) <2013>  Clara Muller <clara.muller19@gmail.com>
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


#ifndef S_MATRIX_H
# define S_MATRIX_H

# include <stdbool.h>
# include <f_memory/f_memory.h>
# include <f_error/m_error.h>
# include <t_types.h>

typedef struct	s_matrix
{
	double	**v_coeff;
	ui		v_columns;
	ui		v_rows;
}				t_matrix;

#define D_MATRIX(funct)	f_matrix_##funct

bool	f_matrix_init(t_matrix *v_this, ui c, ui r);
void	f_matrix_sum(t_matrix *v_this, t_matrix *m1, t_matrix *m2);
void	f_matrix_sub(t_matrix *v_this, t_matrix *m1, t_matrix *m2);
void	f_matrix_div(t_matrix *v_this, t_matrix *m1, t_matrix *m2);
void	f_matrix_mul(t_matrix *v_this, t_matrix *m1, t_matrix *m2);
void	f_matrix_print(const t_matrix *v_this, const char *name);
void	f_matrix_destroy(t_matrix *v_this);

#endif
