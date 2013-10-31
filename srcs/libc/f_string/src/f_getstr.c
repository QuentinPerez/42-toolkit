/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_getstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/30 13:45:49 by qperez            #+#    #+#             */
/*   Updated: 2013/10/31 12:02:52 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains all f_getstr function>
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

#include <unistd.h>
#include <string/s_string.h>
#include <f_error/m_error.h>

static bool	uf_get_data(t_string *string, ui fd, uc terminate, bool del)
{
	char	c;
	ui		nb_read;

	nb_read = read(fd, &c, 1);
	while (nb_read == 1)
	{
		if (del == true && c == terminate)
			return (true);
		if (D_STRING(add_char)(string, c) == false)
			return (false);
		if (c == terminate)
			return (true);
		nb_read = read(fd, &c, 1);
	}
	if (del == false && D_STRING(empty)(string) == false)
		return (D_STRING(add_char)(string, terminate));
	return (true);
}

char		*uf_getstr(ui fd, uc terminate, bool del)
{
	t_string	string;
	char		*ret;

	ret = NULL;
	if (D_STRING(init)(&string, 0) == false)
		return ((char*)m_error((ssize_t)NULL, "Could not initialize string"));
	if (uf_get_data(&string, fd, terminate, del) == true)
		ret = D_STRING(dup)(&string);
	D_STRING(destroy)(&string);
	return (ret);
}

char		*uf_getline(ui fd, bool del)
{
	return (uf_getstr(fd, '\n', del));
}
