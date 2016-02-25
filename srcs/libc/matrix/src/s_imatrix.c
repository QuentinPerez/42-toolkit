/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_imatrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmuller <clara.muller19@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/09 20:57:21 by cmuller           #+#    #+#             */
/*   Updated: 2014/12/02 11:25:47 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_imatrix function>
** < init, destroy >
** Copyright (C) <2013> Clara Muller <clara.muller19@gmail.com>
** This file is part of 42-toolkit.
** 42-toolkit is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU General Public License for more details.
** You should have received a copy of the GNU General Public License
** along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <matrix/s_imatrix.h>
#include <f_memory/f_free.h>
#include <f_secure/f_secure.h>
#include <stdint.h>

static bool	uf_imatrix_fillcoeff(t_imatrix *v_this, size_t col, size_t row)
{
	size_t	i;

	i = 0;
	while (i < row)
	{
		if ((v_this->v_coeff[i] = uf_malloc_s(col,
									sizeof(*v_this->v_coeff[i]))) == NULL)
		{
			uf_free_tab_fail((void **)v_this->v_coeff, i);
			return (M_ERROR(false, "Bad alloc"));
		}
		uf_memset(v_this->v_coeff[i], 0, sizeof(*v_this->v_coeff[i]) * col);
		i = i + 1;
	}
	v_this->v_coeff[i] = NULL;
	return (true);
}

bool		f_imatrix_init(t_imatrix *v_this, size_t c, size_t r)
{
	if (c == 0 || r == 0)
		return (M_ERROR(false, "Columns != 0 && Rows != 0"));
	if ((v_this->v_coeff = uf_malloc_s(r + 1,
									sizeof(*v_this->v_coeff))) == NULL)
		return (M_ERROR(false, "Bad alloc"));
	uf_memset(v_this->v_coeff, 0, sizeof(*v_this->v_coeff) * (r + 1));
	if (uf_imatrix_fillcoeff(v_this, c, r) == false)
		return (false);
	v_this->v_columns = c;
	v_this->v_rows = r;
	return (true);
}

void		f_imatrix_destroy(t_imatrix *v_this)
{
	uf_free_tab((void **)v_this->v_coeff);
	v_this->v_coeff = NULL;
	v_this->v_columns = 0;
	v_this->v_rows = 0;
}
