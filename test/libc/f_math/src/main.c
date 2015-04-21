/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2013/11/05 14:02:45 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_math/f_convert.h>
#include <f_math/f_math.h>
#include <unit/s_unit.h>

void	D_UNIT_FUNCT(ret_val)
{
	F_UNIT_ASSERT((int)uf_deg_to_rad(100) == 1);
	F_UNIT_ASSERT((int)uf_rad_to_deg(1) == 57);
	F_UNIT_ASSERT((int)uf_abs(-42) == 42);
	F_UNIT_ASSERT((int)uf_abs(42) == 42);
	F_UNIT_ASSERT((int)uf_min(42, 57) == 42);
	F_UNIT_ASSERT((int)uf_max(42, 57) == 57);
}

int		main(int argc, char const** argv)
{
	t_unit	unit;

	D_UNIT(init)(&unit);
	D_UNIT(add_context)(&unit, "Method", 0, 0);
	F_UNIT_ADD_TEST(&unit, "Method", ret_val);
	D_UNIT(console_run)(&unit);
	D_UNIT(destroy)(&unit);
	(void)argc;
	(void)argv;
	return (0);
}
