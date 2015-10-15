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

#include <stddef.h>
#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>
#include <error/s_error.h>
#include <unistd.h>



static void
init(void **state) {
	t_error	error;

	assert_true(D_ERROR(init)(&error, "file.txt"));
	D_ERROR(destroy)(&error);
	(void)state;
}

static void
add(void **state) {
	t_error	error;

	assert_true(D_ERROR(init)(&error, "file.txt"));
	assert_true(F_ERROR_ADD(&error, true, "%s", "coucou"));
	assert_false(F_ERROR_ADD(&error, false, "%s", "coucou 2"));
	D_ERROR(destroy)(&error);
	(void)state;
}

static void
init_multiple(void **state) {
	t_error	error;

	assert_true(D_ERROR(init)(&error, "file.txt"));
	D_ERROR(destroy)(&error);
	assert_true(D_ERROR(init)(&error, "file.txt"));
	D_ERROR(destroy)(&error);
	(void)state;
}

static void
init_bad_file(void **state) {
	t_error	error;

	assert_false(D_ERROR(init)(&error, "/toto"));
	D_ERROR(destroy)(&error);
	(void)state;
}

int
main(int argc, char const** argv) {
	const struct CMUnitTest	test[] = {
		cmocka_unit_test(init),
		cmocka_unit_test(init_multiple),
		cmocka_unit_test(init_bad_file),
		cmocka_unit_test(add),
	};

	(void)argc;
	(void)argv;
	return (cmocka_run_group_tests(test, 0, 0));
}
