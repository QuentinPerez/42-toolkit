/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/21 23:44:08 by qperez            #+#    #+#             */
/*   Updated: 2013/11/04 20:33:34 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_math/f_convert.h>
#include <f_math/f_math.h>
#include <f_string/f_print.h>

/*
 * This file is a little example of math functions
 */

int	main(int argc, char const** argv)
{
	/*
	 * Convert 240 deg to rad
	 */
	uf_print_variadic("Convert 240 deg to rad %d\n", (int)uf_deg_to_rad(240));
	/*
	 * Convert 240 deg to rad
	 */
	uf_print_variadic("Convert 4 rad to deg %d\n", (int)uf_rad_to_deg(4));
	/*
	 * And absolue value
	 */
	uf_print_variadic("Absolue value -42 = %d\n", (int)uf_abs(-42));
	(void)argc;
	(void)argv;
	return (0);
}

