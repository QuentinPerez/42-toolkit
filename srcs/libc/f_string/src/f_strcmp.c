/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strcmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/07 20:14:55 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:40:43 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains f_strcmp function>
** < uf_strcmp, uf_strncmp >
** Copyright (C) <2013>  Quentin Perez <qperez42@gmail.com>
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

#include <stddef.h>

int	uf_strcmp(const char *left, const char *right)
{
	while (*left != '\0' && *right != '\0' && *right == *left)
	{
		left = left + 1;
		right = right + 1;
	}
	return ((int)((unsigned char)*left - (unsigned char)*right));
}

int	uf_strncmp(const char *left, const char *right, size_t count)
{
	if (count == 0)
		return (0);
	while (*left != '\0' && *right != '\0' && *right == *left && count != 0)
	{
		count = count - 1;
		if (count == 0)
			break ;
		left = left + 1;
		right = right + 1;
	}
	return ((int)((unsigned char)*left - (unsigned char)*right));
}
