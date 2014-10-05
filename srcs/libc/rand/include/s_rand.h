/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/05 11:30:57 by qperez            #+#    #+#             */
/*   Updated: 2014/10/05 13:36:31 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains rand prototype>
** Copyright (C) <2014>  Quentin Perez <qperez42@gmail.com>
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

#ifndef S_RAND_H
# define S_RAND_H

# include <stdbool.h>
# include <unistd.h>

typedef enum	e_type_rand
{
	e_rand_std = 0,
	e_rand_file,
	e_rand_max
}				t_type_rand;

typedef struct	s_rand
{
	int			v_fd;
	t_type_rand	v_style;
}				t_rand;

# define D_RAND(funct)	f_rand_##funct

bool	f_rand_init(t_rand *v_this, t_type_rand style);
bool	f_rand_change_seed(t_rand *v_this, size_t seed);
ssize_t	f_rand_generate(t_rand *v_this);
void	f_rand_destroy(t_rand *v_this);

#endif
