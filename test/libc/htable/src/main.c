/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2014/09/03 16:51:30 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>
#include <htable/s_htable.h>
#include <stdio.h>

static void
erase(void **state) {
	t_htable	htable;

	assert_true(D_HTABLE(init)(&htable, 997, NULL, NULL));
	assert_true(D_HTABLE(add)(&htable, "key", (void*)(uintptr_t)1));
	assert_int_equal((uintptr_t)D_HTABLE(erase)(&htable, "key"), 1);
	assert_null(D_HTABLE(get)(&htable, "key"));
	D_HTABLE(destroy)(&htable);
	(void)state;
}

static void
delete(void **state) {
	t_htable	htable;

	assert_true(D_HTABLE(init)(&htable, 997, NULL, NULL));
	assert_true(D_HTABLE(add)(&htable, "key", (void*)(uintptr_t)1));
	D_HTABLE(delete)(&htable, "key");
	assert_null(D_HTABLE(get)(&htable, "key"));
	D_HTABLE(destroy)(&htable);
	(void)state;
}

static void
get(void **state) {
	t_htable	htable;

	assert_true(D_HTABLE(init)(&htable, 997, NULL, NULL));
	assert_true(D_HTABLE(add)(&htable, "key", (void*)(uintptr_t)1));
	assert_int_equal((uintptr_t)D_HTABLE(get)(&htable, "key"), 1);

	D_HTABLE(destroy)(&htable);
	(void)state;
}

static void
add(void **state) {
	t_htable	htable;

	assert_true(D_HTABLE(init)(&htable, 997, NULL, NULL));
	assert_true(D_HTABLE(add)(&htable, "key", (void*)(uintptr_t)1));
	D_HTABLE(destroy)(&htable);
	(void)state;
}

static void
init(void **state) {
	t_htable	htable;

	assert_true(D_HTABLE(init)(&htable, 997, NULL, NULL));
	D_HTABLE(destroy)(&htable);
	(void)state;
}

int
main(int argc, char const** argv) {
	const struct CMUnitTest	test[] = {
		cmocka_unit_test(init),
		cmocka_unit_test(add),
		cmocka_unit_test(get),
		cmocka_unit_test(delete),
		cmocka_unit_test(erase),
	};

	(void)argc;
	(void)argv;
	return (cmocka_run_group_tests(test, 0, 0));
}
