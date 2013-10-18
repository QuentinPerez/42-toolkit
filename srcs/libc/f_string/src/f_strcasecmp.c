/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strcasecmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/07 23:03:19 by qperez            #+#    #+#             */
/*   Updated: 2013/10/07 23:37:24 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains function>
** < uf_str_case_cmp, uf_str_case_ncmp >
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
#include <f_string/f_char.h>
#include <stddef.h>

int	uf_str_case_cmp(const char *left, const char *right)
{
	uc	left_letter;
	uc	right_letter;

	while (*left != '\0' && *right != '\0')
	{
		left_letter = uf_to_lower(*left);
		right_letter = uf_to_lower(*right);
		if (left_letter != right_letter)
			break ;
		right = right + 1;
		left = left + 1;
	}
	return ((int)((uc)*left - (uc)*right));
}

int	uf_str_case_ncmp(const char *left, const char *right, size_t count)
{
	uc	left_letter;
	uc	right_letter;

	if (count == 0)
		return (0);
	while (*left != '\0' && *right != '\0' && count != 0)
	{
		left_letter = uf_to_lower(*left);
		right_letter = uf_to_lower(*right);
		count = count - 1;
		if (left_letter != right_letter)
			break ;
		if (count == 0)
			return (0);
		right = right + 1;
		left = left + 1;
	}
	return ((int)((uc)*left - (uc)*right));

}
