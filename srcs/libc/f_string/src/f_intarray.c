/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_intarray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/31 17:58:49 by qperez            #+#    #+#             */
/*   Updated: 2013/10/31 18:06:22 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains function>
** < uf_itoa_base, uf_itoa >
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
#include <string/s_string.h>

char	*uf_itoa_base(int nbr, ui base)
{
	char		*ret;
	t_string	str;

	ret = NULL;
	if (D_STRING(init)(&str, 0) == true &&
		D_STRING(add_nbr_base)(&str, nbr, base) == true)
		ret = D_STRING(dup)(&str);
	D_STRING(destroy)(&str);
	return (ret);
}

char	*uf_itoa(int nbr)
{
	return (uf_itoa_base(nbr, 10));
}
