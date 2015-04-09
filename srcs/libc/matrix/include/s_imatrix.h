/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_imatrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmuller <clara.muller19@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/09 19:20:01 by cmuller           #+#    #+#             */
/*   Updated: 2014/10/05 13:00:43 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_imatrix prototype>
** Copyright (C) <2013>  Clara Muller <clara.muller19@gmail.com>
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


#ifndef S_IMATRIX_H
# define S_IMATRIX_H

# include <stdbool.h>
# include <f_memory/f_memory.h>
# include <f_error/m_error.h>
# include <stddef.h>

typedef struct	s_imatrix
{
	int		**v_coeff;
	size_t	v_columns;
	size_t	v_rows;
}				t_imatrix;

#define D_IMATRIX(funct)	f_imatrix_##funct

bool	f_imatrix_init(t_imatrix *v_this, size_t c, size_t r);
void	f_imatrix_sum(t_imatrix *v_this, t_imatrix *m1, t_imatrix *m2);
void	f_imatrix_sub(t_imatrix *v_this, t_imatrix *m1, t_imatrix *m2);
void	f_imatrix_print(const t_imatrix *v_this, const char *name);
void	f_imatrix_destroy(t_imatrix *v_this);

#endif
