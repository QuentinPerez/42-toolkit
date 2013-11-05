/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2013/11/05 14:38:03 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_string/f_string.h>
#include <f_string/f_char.h>
#include <f_string/f_str_tools.h>
#include <f_string/f_space.h>
#include <unit/s_unit.h>

void	D_UNIT_FUNCT(ret_val)
{
	D_UNIT(assert)(uf_is_upper('A') == true);
	D_UNIT(assert)(uf_is_upper('a') == false);
	D_UNIT(assert)(uf_is_lower('A') == false);
	D_UNIT(assert)(uf_is_lower('a') == true);
	D_UNIT(assert)(uf_is_alpha('a') == true);
	D_UNIT(assert)(uf_is_alpha('9') == false);
	D_UNIT(assert)(uf_is_printable(0) == false);
	D_UNIT(assert)(uf_is_printable('a') == true);
	D_UNIT(assert)(uf_is_digit('a') == false);
	D_UNIT(assert)(uf_is_digit('9') == true);
	D_UNIT(assert)(uf_is_space(' ') == true);
	D_UNIT(assert)(uf_is_space('9') == false);
	D_UNIT(assert)(uf_str_len("") == 0);
	D_UNIT(assert)(uf_str_len("foo") == 3);
	D_UNIT(assert)(uf_strcmp("foo", "foo") == 0);
	D_UNIT(assert)(uf_strcmp("foo", "fDo") != 0);
	D_UNIT(assert)(uf_strncmp("foo", "foo", 2) == 0);
	D_UNIT(assert)(uf_strncmp("foo", "fDo", 2) != 0);
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
