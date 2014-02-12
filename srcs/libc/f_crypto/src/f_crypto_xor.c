/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_crypto_xor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/18 17:21:22 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:32:49 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains f_crypto_xor function>
** < xor >
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

#include <t_types.h>
#include <f_string/f_str_tools.h>

void	uf_crypto_xor(void *data, const char *key, t_ui data_size)
{
	t_ui	i;
	t_ui	len;

	i = 0;
	len = uf_str_len(key);
	if (len == 0)
		return ;
	while (i < data_size)
	{
		if (((t_uc *)data)[i] != 0 && ((t_uc *)data)[i] != key[i % len])
			((t_uc *)data)[i] = ((t_uc *)data)[i] ^ key[i % len];
		i = i + 1;
	}
}
