/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2014/09/03 17:49:23 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>
#include <arqueue/s_arqueue.h>
#include <stdio.h>

static void
empty(void **state) {
	t_arqueue	arqueue;
	int			i = 10;

	assert_true(D_ARQUEUE(init)(&arqueue, 10, sizeof(int)));
	assert_true(D_ARQUEUE(empty)(&arqueue));
	assert_true(D_ARQUEUE(push)(&arqueue, &i));
	assert_false(D_ARQUEUE(empty)(&arqueue));
	assert_int_equal(*(int *)D_ARQUEUE(pop)(&arqueue), i);
	assert_true(D_ARQUEUE(empty)(&arqueue));
	D_ARQUEUE(destroy);
	(void)state;
}

static void
pop(void **state) {
	t_arqueue	arqueue;
	int			i = 10;

	assert_true(D_ARQUEUE(init)(&arqueue, 10, sizeof(int)));
	assert_true(D_ARQUEUE(push)(&arqueue, &i));
	assert_int_equal(*(int *)D_ARQUEUE(pop)(&arqueue), i);
	assert_ptr_equal(D_ARQUEUE(pop)(&arqueue), 0);
	D_ARQUEUE(destroy);
	(void)state;
}

static void
push(void **state) {
	t_arqueue	arqueue;
	int			i = 10;

	assert_true(D_ARQUEUE(init)(&arqueue, 10, sizeof(int)));
	assert_true(D_ARQUEUE(push)(&arqueue, &i));
	assert_int_equal(*(int *)D_ARQUEUE(pop)(&arqueue), i);
	D_ARQUEUE(destroy);
	(void)state;
}

static void
init_with_zero(void **state) {
	t_arqueue	arqueue;

	assert_false(D_ARQUEUE(init)(&arqueue, 0, sizeof(int)));
	D_ARQUEUE(destroy);
	assert_false(D_ARQUEUE(init)(&arqueue, 10, 0));
	D_ARQUEUE(destroy);
	(void)state;
}

static void
destroy(void **state) {
	t_arqueue	arqueue;

	assert_true(D_ARQUEUE(init)(&arqueue, 10, sizeof(int)));
	D_ARQUEUE(destroy);
	assert_true(D_ARQUEUE(init)(&arqueue, 100, sizeof(int)));
	D_ARQUEUE(destroy);
	(void)state;
}

static void
multiple_destroy(void **state) {
	t_arqueue	arqueue;

	assert_true(D_ARQUEUE(init)(&arqueue, 10, sizeof(int)));
	D_ARQUEUE(destroy);
	D_ARQUEUE(destroy);
	(void)state;
}

static void
init(void **state) {
	t_arqueue	arqueue;

	assert_true(D_ARQUEUE(init)(&arqueue, 10, sizeof(int)));
	D_ARQUEUE(destroy);
	(void)state;
}

int
main(int argc, char const** argv) {
	const struct CMUnitTest	test[] = {
		cmocka_unit_test(init),
		cmocka_unit_test(init_with_zero),
		cmocka_unit_test(push),
		cmocka_unit_test(destroy),
		cmocka_unit_test(multiple_destroy),
		cmocka_unit_test(pop),
		cmocka_unit_test(empty),
	};

	(void)argc;
	(void)argv;
	return (cmocka_run_group_tests(test, 0, 0));
}
