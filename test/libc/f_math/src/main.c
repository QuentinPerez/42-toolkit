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

#include <stddef.h>
#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>
#include <f_math/f_math.h>

static void
t_abs(void **state) {
	assert_int_equal(uf_abs(-10), 10);
	assert_int_equal(uf_abs(10), 10);
	assert_int_equal(uf_abs(0), 0);
	(void)state;
}

static void
t_min(void **state) {
	assert_int_equal(uf_min(-10, 10), -10);
	assert_int_equal(uf_min(10, 100), 10);
	assert_int_equal(uf_min(-10, -20), -20);
	assert_int_equal(uf_min(0, 0), 0);
	(void)state;
}

static void
t_max(void **state) {
	assert_int_equal(uf_max(-10, 10), 10);
	assert_int_equal(uf_max(10, 100), 100);
	assert_int_equal(uf_max(-10, -20), -10);
	assert_int_equal(uf_max(0, 0), 0);
	(void)state;
}

int
main(int argc, char const** argv) {
	const struct CMUnitTest	test[] = {
		cmocka_unit_test(t_abs),
		cmocka_unit_test(t_min),
		cmocka_unit_test(t_max),
	};

	(void)argc;
	(void)argv;
	return (cmocka_run_group_tests(test, 0, 0));
}
