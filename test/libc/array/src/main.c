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
#include <array/s_array.h>
#include <stdio.h>

static void
data(void **state) {
	t_array	array;

	assert_true(D_ARRAY(init)(&array, 0, 0, sizeof(size_t)));
	assert_ptr_equal(F_ARRAY_DATA(&array, size_t *), array.v_data);
	D_ARRAY(destroy)(&array);
	(void)state;
}

static void
at_out_of_range(void **state) {
	t_array	array;

	assert_true(D_ARRAY(init)(&array, 0, 0, sizeof(size_t)));
	assert_null(F_ARRAY_AT(&array, 0, size_t));
	D_ARRAY(destroy)(&array);
	(void)state;
}

static void
at(void **state) {
	t_array	array;
	size_t	put = 0;

	assert_true(D_ARRAY(init)(&array, 0, 0, sizeof(size_t)));
	assert_true(D_ARRAY(push_back)(&array, &put));
	put++;
	assert_non_null(F_ARRAY_AT(&array, 0, size_t));
	assert_int_equal(*(size_t *)F_ARRAY_AT(&array, 0, size_t), 0);
	D_ARRAY(destroy)(&array);
	(void)state;
}

static bool
uf_cmp(void *d1, void *d2) {
	return (*(size_t *)d1 == *(size_t *)d2);
}

static void
delete_if(void **state) {
	t_array	array;
	size_t	put = 0;
	size_t	cmp = 1;

	assert_true(D_ARRAY(init)(&array, 0, 0, sizeof(size_t)));
	assert_true(D_ARRAY(push_back)(&array, &put));
	put++;
	assert_true(D_ARRAY(push_back)(&array, &put));
	put++;
	assert_true(D_ARRAY(push_back)(&array, &put));
	put++;
	D_ARRAY(delete_if)(&array, uf_cmp, &cmp);
	assert_int_equal(*(size_t *)F_ARRAY_AT(&array, 0, size_t), 0);
	assert_int_equal(*(size_t *)F_ARRAY_AT(&array, 1, size_t), 2);
	assert_int_equal(D_ARRAY(size)(&array), 2);
	D_ARRAY(destroy)(&array);
	(void)state;
}
static void
delete_if_double(void **state) {
	t_array	array;
	size_t	put = 0;
	size_t	cmp = 1;

	assert_true(D_ARRAY(init)(&array, 0, 0, sizeof(size_t)));
	assert_true(D_ARRAY(push_back)(&array, &put));
	put++;
	assert_true(D_ARRAY(push_back)(&array, &put));
	assert_true(D_ARRAY(push_back)(&array, &put));
	put++;
	assert_true(D_ARRAY(push_back)(&array, &put));
	put++;
	D_ARRAY(delete_if)(&array, uf_cmp, &cmp);
	assert_int_equal(*(size_t *)F_ARRAY_AT(&array, 0, size_t), 0);
	assert_int_equal(*(size_t *)F_ARRAY_AT(&array, 1, size_t), 2);
	assert_int_equal(D_ARRAY(size)(&array), 2);
	D_ARRAY(destroy)(&array);
	(void)state;
}

static void
delete_if_last(void **state) {
	t_array	array;
	size_t	put = 0;
	size_t	cmp = 2;

	assert_true(D_ARRAY(init)(&array, 0, 0, sizeof(size_t)));
	assert_true(D_ARRAY(push_back)(&array, &put));
	put++;
	assert_true(D_ARRAY(push_back)(&array, &put));
	put++;
	assert_true(D_ARRAY(push_back)(&array, &put));
	put++;
	D_ARRAY(delete_if)(&array, uf_cmp, &cmp);
	assert_int_equal(*(size_t *)F_ARRAY_AT(&array, 0, size_t), 0);
	assert_int_equal(*(size_t *)F_ARRAY_AT(&array, 1, size_t), 1);
	assert_int_equal(D_ARRAY(size)(&array), 2);
	D_ARRAY(destroy)(&array);
	(void)state;
}

static void
delete_if_first(void **state) {
	t_array	array;
	size_t	put = 0;
	size_t	cmp = 0;

	assert_true(D_ARRAY(init)(&array, 0, 0, sizeof(size_t)));
	assert_true(D_ARRAY(push_back)(&array, &put));
	put++;
	assert_true(D_ARRAY(push_back)(&array, &put));
	put++;
	assert_true(D_ARRAY(push_back)(&array, &put));
	put++;
	D_ARRAY(delete_if)(&array, uf_cmp, &cmp);
	assert_int_equal(*(size_t *)F_ARRAY_AT(&array, 0, size_t), 1);
	assert_int_equal(*(size_t *)F_ARRAY_AT(&array, 1, size_t), 2);
	assert_int_equal(D_ARRAY(size)(&array), 2);
	D_ARRAY(destroy)(&array);
	(void)state;
}

static size_t	uf_realloc(size_t size) {
	return (size + 1);
}

static void
resize(void **state) {
	t_array	array;

	assert_true(D_ARRAY(init)(&array, uf_realloc, 0, sizeof(size_t)));
	assert_true(D_ARRAY(resize)(&array, 10));
	assert_int_equal(D_ARRAY(capacity)(&array), 10);
	assert_int_equal(D_ARRAY(size)(&array), 0);
	D_ARRAY(destroy)(&array);
	(void)state;
}

static void
resize_fail(void **state) {
	t_array	array;

	assert_true(D_ARRAY(init)(&array, uf_realloc, 0, sizeof(size_t)));
	assert_true(D_ARRAY(resize)(&array, 10));
	assert_false(D_ARRAY(resize)(&array, 1));
	D_ARRAY(destroy)(&array);
	(void)state;
}

static void
capacity(void **state) {
	t_array	array;
	size_t	put = 0;

	assert_true(D_ARRAY(init)(&array, uf_realloc, 0, sizeof(size_t)));
	assert_true(D_ARRAY(push_back)(&array, &put));
	put++;
	assert_true(D_ARRAY(push_back)(&array, &put));
	assert_int_equal(D_ARRAY(capacity)(&array), 2);
	put++;
	assert_true(D_ARRAY(push_back)(&array, &put));
	assert_int_equal(D_ARRAY(capacity)(&array), 3);
	D_ARRAY(destroy)(&array);
	(void)state;
}


static void
destroy(void **state) {
	t_array	array;
	size_t	put = 4;

	assert_true(D_ARRAY(init)(&array, 0, 0, sizeof(size_t)));
	assert_true(D_ARRAY(push_back)(&array, &put));
	assert_int_equal(D_ARRAY(size)(&array), 1);
	assert_int_equal(*(size_t *)F_ARRAY_AT(&array, 0, size_t), 4);
	D_ARRAY(destroy)(&array);
	assert_true(D_ARRAY(init)(&array, 0, 0, sizeof(size_t)));
	assert_true(D_ARRAY(push_back)(&array, &put));
	assert_int_equal(D_ARRAY(size)(&array), 1);
	assert_int_equal(*(size_t *)F_ARRAY_AT(&array, 0, size_t), 4);
	D_ARRAY(destroy)(&array);
	(void)state;
}

static bool
uf_foreach(void *data) {
	size_t	*value = (size_t*)data;

	*value = *value + 10;
	return true;
}

static void
foreach(void **state) {
	t_array	array;
	size_t	put;

	assert_true(D_ARRAY(init)(&array, 0, 0, sizeof(size_t)));
	for (put = 0; put < 10; put++) {
		assert_true(D_ARRAY(push_back)(&array, &put));
	}
	D_ARRAY(foreach)(&array, uf_foreach);
	for (put = 0; put < 10; put++) {
		assert_int_equal(*(size_t *)F_ARRAY_AT(&array, put, size_t), put + 10);
	}
	D_ARRAY(destroy)(&array);
	(void)state;
}

static void
empty(void **state) {
	t_array	array;
	size_t	put;

	assert_true(D_ARRAY(init)(&array, 0, 0, sizeof(int)));
	for (put = 0; put < 10; put++) {
		assert_true(D_ARRAY(push_back)(&array, &put));
	}
	assert_false(D_ARRAY(empty)(&array));
	D_ARRAY(clear)(&array);
	assert_true(D_ARRAY(empty)(&array));
	D_ARRAY(destroy)(&array);
	(void)state;
}

static void
clear_and_push_back(void **state) {
	t_array	array;
	size_t	put;

	assert_true(D_ARRAY(init)(&array, 0, 0, sizeof(int)));
	for (put = 0; put < 10; put++) {
		assert_true(D_ARRAY(push_back)(&array, &put));
	}
	D_ARRAY(clear)(&array);
	assert_int_equal(D_ARRAY(size)(&array), 0);
	for (put = 0; put < 10; put++) {
		assert_true(D_ARRAY(push_back)(&array, &put));
	}
	assert_int_equal(D_ARRAY(size)(&array), 10);
	D_ARRAY(destroy)(&array);
	(void)state;
}

static void
clear(void **state) {
	t_array	array;
	size_t	put;

	assert_true(D_ARRAY(init)(&array, 0, 0, sizeof(int)));
	for (put = 0; put < 10; put++) {
		assert_true(D_ARRAY(push_back)(&array, &put));
	}
	D_ARRAY(clear)(&array);
	assert_int_equal(D_ARRAY(size)(&array), 0);
	D_ARRAY(destroy)(&array);
	(void)state;
}

static void
push_back_1000_values(void **state) {
	t_array	array;
	size_t	put;

	assert_true(D_ARRAY(init)(&array, 0, 0, sizeof(size_t)));
	for (put = 0; put < 1000; put++) {
		assert_true(D_ARRAY(push_back)(&array, &put));
		assert_int_equal(D_ARRAY(size)(&array), put + 1);
	}
	for (put = 0; put < 1000; put++) {
		assert_int_equal(*(size_t *)F_ARRAY_AT(&array, put, size_t), put);
	}
	D_ARRAY(destroy)(&array);
	(void)state;
}

static void
push_back_10_values(void **state) {
	t_array	array;
	size_t	put;

	assert_true(D_ARRAY(init)(&array, 0, 0, sizeof(size_t)));
	for (put = 0; put < 10; put++) {
		assert_true(D_ARRAY(push_back)(&array, &put));
		assert_int_equal(D_ARRAY(size)(&array), put + 1);
	}
	for (put = 0; put < 10; put++) {
		assert_int_equal(*(size_t *)F_ARRAY_AT(&array, put, size_t), put);
	}
	D_ARRAY(destroy)(&array);
	(void)state;
}

static void
push_back(void **state) {
	t_array	array;
	size_t	put = 4;

	assert_true(D_ARRAY(init)(&array, 0, 0, sizeof(size_t)));
	assert_true(D_ARRAY(push_back)(&array, &put));
	assert_int_equal(D_ARRAY(size)(&array), 1);
	assert_int_equal(*(size_t *)F_ARRAY_AT(&array, 0, size_t), 4);
	D_ARRAY(destroy)(&array);
	(void)state;
}

static void
init(void **state) {
	t_array	array;

	assert_true(D_ARRAY(init)(&array, 0, 0, sizeof(int)));
	D_ARRAY(destroy)(&array);
	(void)state;
}

int
main(int argc, char const** argv) {
	const struct CMUnitTest	test[] = {
		cmocka_unit_test(init),
		cmocka_unit_test(push_back),
		cmocka_unit_test(push_back_10_values),
		cmocka_unit_test(push_back_1000_values),
		cmocka_unit_test(clear),
		cmocka_unit_test(clear_and_push_back),
		cmocka_unit_test(empty),
		cmocka_unit_test(foreach),
		cmocka_unit_test(destroy),
		cmocka_unit_test(capacity),
		cmocka_unit_test(delete_if),
		cmocka_unit_test(delete_if_double),
		cmocka_unit_test(delete_if_last),
		cmocka_unit_test(delete_if_first),
		cmocka_unit_test(at),
		cmocka_unit_test(at_out_of_range),
		cmocka_unit_test(data),
		cmocka_unit_test(resize),
		cmocka_unit_test(resize_fail),
	};

	(void)argc;
	(void)argv;
	return (cmocka_run_group_tests(test, 0, 0));
}
