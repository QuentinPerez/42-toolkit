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
	F_UNIT_ASSERT(uf_is_upper('A') == true);
	F_UNIT_ASSERT(uf_is_upper('a') == false);
	F_UNIT_ASSERT(uf_is_lower('A') == false);
	F_UNIT_ASSERT(uf_is_lower('a') == true);
	F_UNIT_ASSERT(uf_is_alpha('a') == true);
	F_UNIT_ASSERT(uf_is_alpha('9') == false);
	F_UNIT_ASSERT(uf_is_printable(0) == false);
	F_UNIT_ASSERT(uf_is_printable('a') == true);
	F_UNIT_ASSERT(uf_is_digit('a') == false);
	F_UNIT_ASSERT(uf_is_digit('9') == true);
	F_UNIT_ASSERT(uf_is_space(' ') == true);
	F_UNIT_ASSERT(uf_is_space('9') == false);
	F_UNIT_ASSERT(uf_str_len("") == 0);
	F_UNIT_ASSERT(uf_str_len("foo") == 3);
	F_UNIT_ASSERT(uf_strcmp("foo", "foo") == 0);
	F_UNIT_ASSERT(uf_strcmp("foo", "fDo") != 0);
	F_UNIT_ASSERT(uf_strncmp("foo", "foo", 2) == 0);
	F_UNIT_ASSERT(uf_strncmp("foo", "fDo", 2) != 0);
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
