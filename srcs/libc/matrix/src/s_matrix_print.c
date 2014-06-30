/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_matrix_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/12 18:00:21 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:49:21 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_matrix_print function>
** < print >
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
#include <f_string/f_print.h>

void	f_matrix_print(const t_matrix *v_this, const char *name)
{
	size_t	i;
	size_t	j;

	i = 0;
	uf_print_str("Matrix ");
	if (name != NULL)
		uf_print_str(name);
	uf_print_variadic(":\n", name);
	while (i < v_this->v_rows)
	{
		j = 0;
		while (j < v_this->v_columns)
		{
			uf_print_variadic("[%d]", (int)v_this->v_coeff[i][j]);
			j = j + 1;
		}
		uf_print_char('\n');
		i = i + 1;
	}
}
