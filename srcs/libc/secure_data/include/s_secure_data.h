/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_secure_data.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/05 11:30:57 by qperez            #+#    #+#             */
/*   Updated: 2014/10/05 13:36:31 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains secure_data prototype>
** Copyright (C) <2015>  Quentin Perez <qperez42@gmail.com>
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

#ifndef S_SECURE_DATA_H
# define S_SECURE_DATA_H

# include <stdbool.h>

typedef struct	s_secure_data
{
}				t_secure_data;

# define D_SECURE_DATA(funct)	f_secure_data_##funct

bool	f_secure_data_init(t_secure_data *v_this);
void	f_secure_data_destroy(t_secure_data *v_this);

#endif
