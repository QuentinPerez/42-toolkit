/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_matrix_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmuller <clara.muller19@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/09 20:57:21 by cmuller           #+#    #+#             */
/*   Updated: 2014/02/12 19:49:08 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_matrix_op method>
** < sum, sub, mul, div >
** Copyright (C) <2013> Clara Muller <clara.muller19@gmail.com>
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
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <matrix/s_matrix.h>

void	f_matrix_sum(t_matrix *v_this, t_matrix *m1, t_matrix *m2)
{
	t_ui	i;
	t_ui	j;

	i = 0;
	if (m1->v_rows != m2->v_rows || m1->v_columns != m2->v_columns)
		return ;
	while (i < m1->v_rows)
	{
		j = 0;
		while (j < m1->v_columns)
		{
			v_this->v_coeff[i][j] = m1->v_coeff[i][j] + m2->v_coeff[i][j];
			j = j + 1;
		}
		i = i + 1;
	}
}

void	f_matrix_sub(t_matrix *v_this, t_matrix *m1, t_matrix *m2)
{
	t_ui	i;
	t_ui	j;

	i = 0;
	if (m1->v_rows != m2->v_rows || m1->v_columns != m2->v_columns)
		return ;
	while (i < m1->v_rows)
	{
		j = 0;
		while (j < m1->v_columns)
		{
			v_this->v_coeff[i][j] = m1->v_coeff[i][j] - m2->v_coeff[i][j];
			j = j + 1;
		}
		i = i + 1;
	}
}

void	f_matrix_mul(t_matrix *v_this, t_matrix *m1, int c)
{
	t_ui	i;
	t_ui	j;

	i = 0;
	while (i < m1->v_rows)
	{
		j = 0;
		while (j < m1->v_columns)
		{
			v_this->v_coeff[i][j] = m1->v_coeff[i][j] * c;
			j = j + 1;
		}
		i = i + 1;
	}
}

void	f_matrix_div(t_matrix *v_this, t_matrix *m1, t_matrix *m2)
{
	t_ui	i;
	t_ui	j;

	i = 0;
	if (m1->v_rows != m2->v_rows || m1->v_columns != m2->v_columns)
		return ;
	while (i < m1->v_rows)
	{
		j = 0;
		while (j < m1->v_columns)
		{
			if (m1->v_coeff[i][j] != 0 && m2->v_coeff[i][j] != 0)
				v_this->v_coeff[i][j] = m1->v_coeff[i][j] * m2->v_coeff[i][j];
			j = j + 1;
		}
		i = i + 1;
	}
}
