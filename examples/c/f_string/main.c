/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 18:08:55 by qperez            #+#    #+#             */
/*   Updated: 2013/08/28 18:35:26 by qperez           ###   ########.fr       */
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

#include <f_print_fd.h>
#include <stdio.h>

#define	D_TEST(funct, param)	printf("== "#funct" ==\n"); funct(param, 1)

int	main(int argc, const char **argv)
{
	(void)argc;
	(void)argv;
	D_TEST(uf_print_str_fd, "Hello World\n");
	D_TEST(uf_print_nbr_fd, 42);
	uf_print_char_fd('\n', 1);
	D_TEST(uf_print_char_fd, '!');
	uf_print_char_fd('\n', 1);
	return (0);
}
