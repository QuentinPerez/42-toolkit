/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2014/09/03 16:52:23 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string/s_string.h>
#include <unit/s_unit.h>

void	D_UNIT_FUNCT(memleaks)
{
	unsigned int	i;
	t_string		string;

	i = 0;
	D_STRING(init)(&string, 0);
	while (i < 5)
	{
		D_STRING(add_str)(&string, "hello boys");
		D_STRING(add_nbr)(&string, 42);
		D_STRING(add_ptr)(&string, &string);
		D_STRING(variadic)(&string, "%e%X", 35, 42);
		i = i + 1;
	}
	D_STRING(destroy)(&string);
	(void)t;
}

int		main(int argc, char const** argv)
{
	t_unit	unit;

	D_UNIT(init)(&unit);
	D_UNIT(add_context)(&unit, "Leaks", 0, 0);
	D_UNIT(add_test)(&unit, "Leaks", memleaks);
	D_UNIT(console_run)(&unit);
	D_UNIT(destroy)(&unit);
	(void)argc;
	(void)argv;
	return (0);
}
