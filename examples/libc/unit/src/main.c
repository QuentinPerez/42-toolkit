/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/31 11:15:03 by qperez            #+#    #+#             */
/*   Updated: 2013/11/03 16:44:21 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unit/s_unit.h>
#include <unit/s_unit_test.h>
#include <f_string/f_print.h>
#include <f_string/f_string.h>

void	D_UNIT_FUNCT(string)
{
	D_UNIT(assert)(uf_strcmp("Hello", "Hello") == 0);
}

void	D_UNIT_FUNCT(string2)
{
	D_UNIT(assert)(uf_strcmp("Hello", "42") == 0);
}

void	D_UNIT_FUNCT(integer)
{
	D_UNIT(assert)(14 == 14);
}

void	D_UNIT_FUNCT(integer2)
{
	D_UNIT(assert)(14 == 0);
}

int	main(int argc, char const** argv)
{
	t_unit	unit;

	D_UNIT(init)(&unit);
	D_UNIT(add_context)(&unit, "String test", 0, 0);
	D_UNIT(add_context)(&unit, "Integer test", 0, 0);
	D_UNIT(add_test)(&unit, "Integer test", integer);
	D_UNIT(add_test)(&unit, "Integer test", integer2);
	D_UNIT(add_test)(&unit, "String test", string2);
	D_UNIT(add_test)(&unit, "String test", string);
	D_UNIT(console_run)(&unit);
	D_UNIT(destroy)(&unit);
	(void)argc;
	(void)argv;
	return (0);
}

