/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/31 11:15:03 by qperez            #+#    #+#             */
/*   Updated: 2015/04/19 14:11:31 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unit/s_unit.h>
#include <unit/s_unit_test.h>
#include <f_string/f_print.h>
#include <f_string/f_string.h>

/*
 * This file is a little example of the t_unit structure
 */

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

	/*
	 * disable travis test
	 */
	return (0);
	/*
	 * Initialize unit for that work
	 */
	D_UNIT(init)(&unit);
	/*
	 * Here I add lot of things and I don't check return values
	 * Because I'm warrior
	 */
	/*
	 * Add context make box where after you put test
	 */
	D_UNIT(add_context)(&unit, "String test", 0, 0);
	D_UNIT(add_context)(&unit, "Integer test", 0, 0);
	/*
	 * It's time to push
	 */
	D_UNIT(add_test)(&unit, "Integer test", integer);
	D_UNIT(add_test)(&unit, "Integer test", integer2);
	D_UNIT(add_test)(&unit, "String test", string2);
	D_UNIT(add_test)(&unit, "String test", string);
	/*
	 * Are you ready for ASCII art
	 */
	D_UNIT(console_run)(&unit);
	/*
	 * Good bye memory
	 */
	D_UNIT(destroy)(&unit);
	(void)argc;
	(void)argv;
	return (0);
}

