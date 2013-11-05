/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2013/11/05 13:29:27 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <error/s_error.h>
#include <unit/s_unit.h>
#include <unistd.h>

void	D_UNIT_FUNCT(ret_val)
{
	t_error	error;

	D_UNIT(assert)(D_ERROR(init)(&error, "file.txt") == 1);
	D_UNIT(assert)(D_ERROR(add)(&error, false, "nothing") == false);
	D_UNIT(assert)(D_ERROR(add)(&error, true, "nothing") == true);
	D_ERROR(destroy)(&error);
	unlink("file.txt");
}

int		main(int argc, char const** argv)
{
	t_unit	unit;

	D_UNIT(init)(&unit);
	D_UNIT(add_context)(&unit, "Method", 0, 0);
	D_UNIT(add_test)(&unit, "Method", ret_val);
	D_UNIT(console_run)(&unit);
	D_UNIT(destroy)(&unit);
	(void)argc;
	(void)argv;
	return (0);
}
