/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2013/11/05 12:30:33 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>
#include <f_memory/f_memory.h>
#include <f_memory/f_free.h>
#include <stdio.h>

static void
t_memset(void **state) {
	char	lol[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

	for (size_t i = 0; i < sizeof(lol); i++) {
		uf_memset(lol, '\0', i);
		for (size_t j = 0; j < i; j++) {
			assert_true(lol[j] == '\0');
		}
	}
	(void)state;
}

static void
t_memcpy(void **state) {
	char	lol[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char	lol2[] = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";

	for (size_t i = 0; i < sizeof(lol); i++) {
		uf_memcpy(lol, lol2, i);
		for (size_t j = 0; j < i; j++) {
			assert_true(lol[j] == 'b');
		}
	}
	(void)state;
}

static void
t_memcmp(void **state) {
	unsigned char t1[256];
	unsigned char t2[256];

	for (size_t i = 0; i < 256; i++) {
		t1[i] = (unsigned char)i;
		t2[i] = (unsigned char)i;
	}
	assert_true(uf_memcmp(t1, t2, sizeof(t1)));
	t1[0] = '\1';
	t2[0] = '\1';
	for (size_t i = 0, tmp; i < 256; i++) {
		if (i == 0) {
			tmp = t1[0];
		} else {
			t1[i - 1] = tmp;
		}
		t1[i] = '\0';
		assert_false(uf_memcmp(t1, t2, sizeof(t1)));
	}
	(void)state;
}

int
main(int argc, char const** argv) {
	const struct CMUnitTest	test[] = {
		cmocka_unit_test(t_memset),
		cmocka_unit_test(t_memcpy),
		cmocka_unit_test(t_memcmp),
	};

	(void)argc;
	(void)argv;
	return (cmocka_run_group_tests(test, 0, 0));
}
