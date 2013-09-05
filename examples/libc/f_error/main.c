/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 16:40:56 by qperez            #+#    #+#             */
/*   Updated: 2013/08/28 18:35:10 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <main>
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

#include <m_error.h>
#include <stdio.h>

void	*uf_test_return_function_pointer(void)
{
	void	*(*why)();

	why = &uf_test_return_function_pointer;
	return (void*)(m_error("I return function pointer", (size_t)why));
}

void	*uf_test_return_addr(void)
{
	char	c;
	char	*why;

	why = &c;
	return (void*)(m_error("I return addr", (size_t)why));
}

int		uf_test_return_negative_value(void)
{
	return (m_error("I return -1", -1));
}

int		uf_test_return_value(void)
{
	return (m_error("I return 1", 1));
}

void	uf_test_return_in_function_void(void)
{
	return (m_error_v("I m void"));
}

int		main(int argc, const char **argv)
{
#ifndef	D_ERRORS_ON
	printf("\nIt's better with debug flags use 'make debug'\n\n");
#endif
	printf("\n== Return with different value ==\n");
	printf("\nI receive %d\n----\n", uf_test_return_value());
	printf("\nI receive negative number %d\n----\n", uf_test_return_negative_value());
	printf("\nI receive addr %p\n----\n", uf_test_return_addr());
	printf("\nI receive function pointer %p\n", uf_test_return_function_pointer());
	printf("\n== Return in function void ==\n");
	uf_test_return_in_function_void();
	printf("\n\n== Function infos ==\n");
	m_infos("42 school");
	(void)argv;
	(void)argc;
	return (0);
}
