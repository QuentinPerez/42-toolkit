/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_secure_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/05 11:48:32 by qperez            #+#    #+#             */
/*   Updated: 2015/04/09 15:27:41 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains secure_data method>
** < init, destroy >
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

#include <secure_data/s_secure_data.h>
#include <f_error/m_error.h>
#include <sys/resource.h>

#include <stdio.h>

bool	f_secure_data_init(t_secure_data *v_this)
{
	struct rlimit	rlp;

	rlp.rlim_cur = 0;
	rlp.rlim_max = 0;
	if (setrlimit(RLIMIT_CORE, &rlp) == -1)
		return (M_ERROR(false, "Couldn't set RLIMIT_CORE value"));
	(void)v_this;
	return (true);
}

void	f_secure_data_destroy(t_secure_data *v_this)
{
	(void)v_this;
}
