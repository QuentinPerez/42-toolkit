/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_str_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 15:09:03 by qperez            #+#    #+#             */
/*   Updated: 2013/08/28 18:32:10 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This function contains all f_str_tools function>
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

#include <f_str_tools.h>

size_t	uf_str_len(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len = len + 1;
	}
	return (len);
}
