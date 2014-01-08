/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_intarray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/31 17:58:49 by qperez            #+#    #+#             */
/*   Updated: 2014/01/08 18:01:02 by qperez           ###   ########.fr       */
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
#include <f_string/f_char.h>
#include <f_string/f_space.h>

char		*uf_itoa_base(int nbr, ui base)
{
	char		*ret;
	t_string	str;

	ret = NULL;
	if (D_STRING(init)(&str, 0) == true
		&& D_STRING(add_nbr_base)(&str, nbr, base) == true)
		ret = D_STRING(dup)(&str);
	D_STRING(destroy)(&str);
	return (ret);
}

char		*uf_itoa(int nbr)
{
	return (uf_itoa_base(nbr, 10));
}

static char	*uf_atoi_check_base(const char *nbr, bool *neg, char *c, ui base)
{
	*neg = false;
	*c = *nbr;
	nbr = nbr + 1;
	if (*c == '-' || *c == '+')
	{
		if (*c == '-')
			*neg = true;
		*c = *nbr;
		nbr = nbr + 1;
	}
	if (base == 16 && *c == '0' && (*nbr == 'x' || *nbr == 'X'))
	{
		*c = nbr[1];
		nbr = nbr + 2;
	}
	else if (base == 2 && *c == '0' && (*nbr == 'b' || *nbr == 'B'))
	{
		*c = nbr[1];
		nbr = nbr + 2;
	}
	return ((char *)nbr);
}

int			uf_atoi_base(const char *nbr, ui base)
{
	char	c;
	bool	neg;
	int		ret;

	ret = 0;
	nbr = uf_atoi_check_base(uf_skip_space(nbr), &neg, &c, base);
	while (true)
	{
		if (uf_is_digit(c) == true)
			c = c - '0';
		else if (uf_is_alpha(c) == true)
			c = c - (uf_is_upper(c) == true ? 'A' - 10 : 'a' - 10);
		else
			break ;
		if ((ui)c >= base)
			break ;
		ret = ret * base;
		ret = ret + c;
		c = *nbr;
		nbr = nbr + 1;
	}
	if (neg == true)
		ret = -ret;
	return (ret);
}

int		uf_atoi(const char *nbr)
{
	return (uf_atoi_base(nbr, 10));
}
