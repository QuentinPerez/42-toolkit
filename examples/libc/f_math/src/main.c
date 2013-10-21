/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/21 23:44:08 by qperez            #+#    #+#             */
/*   Updated: 2013/10/21 23:53:21 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_math/f_convert.h>
#include <f_math/f_math.h>
#include <f_string/f_print.h>

int	main(int argc, char const** argv)
{
	uf_print_nbr((int)uf_deg_to_rad(240));
	uf_print_str("\n");
	uf_print_nbr((int)uf_rad_to_deg(4));
	uf_print_str("\n");
	uf_print_nbr((int)uf_abs(-123456789));
	uf_print_str("\n");
	(void)argc;
	(void)argv;
	return (0);
}

