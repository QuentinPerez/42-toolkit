/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2013/11/05 13:58:08 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unit/s_unit.h>
#include <f_error/m_error.h>

void	D_UNIT_FUNCT(ret_val)
{
	D_UNIT(assert)(m_error(false, "") == false);
	D_UNIT(assert)(m_error(true, "") == true);
	D_UNIT(assert)(m_error(1, "") == 1);
	D_UNIT(assert)(m_error(-1, "") == (size_t)-1);
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
