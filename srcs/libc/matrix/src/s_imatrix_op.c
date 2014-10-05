/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_imatrix_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmuller <clara.muller19@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/09 20:57:21 by cmuller           #+#    #+#             */
/*   Updated: 2014/10/05 13:07:55 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_imatrix_op method>
** < sum, sub >
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

#include <matrix/s_imatrix.h>

void	f_imatrix_sum(t_imatrix *v_this, t_imatrix *m1, t_imatrix *m2)
{
	size_t	i;
	size_t	j;

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

void	f_imatrix_sub(t_imatrix *v_this, t_imatrix *m1, t_imatrix *m2)
{
	size_t	i;
	size_t	j;

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
