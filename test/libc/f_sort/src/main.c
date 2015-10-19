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
#include <f_sort/f_sort.h>
#include <stdio.h>

static bool
check_order(int *tab, size_t size) {
	size_t	i = 1;

	while (i < size) {
		if (tab[i] < tab[i - 1])
			return (false);
		i++;
	}
	return (true);
}

static void
bubble(void **state) {
	int	tab[] = {
		10, 46, 76, 1, 5, 23, 6, -19, 19, 19,
		10, 0, 0, -50, -100, 4000
	};

	uf_sort_bubble(tab, sizeof(tab) / sizeof(tab[0]));
	assert_true(check_order(tab, sizeof(tab) / sizeof(tab[0])));
	(void)state;
}

static void
shell(void **state) {
	int	tab[] = {
		10, 46, 76, 1, 5, 23, 6, -19, 19, 19,
		10, 0, 0, -50, -100, 4000
	};

	uf_sort_shell(tab, sizeof(tab) / sizeof(tab[0]));
	assert_true(check_order(tab, sizeof(tab) / sizeof(tab[0])));
	(void)state;
}

static void
quick(void **state) {
	int	tab[] = {
		10, 46, 76, 1, 5, 23, 6, -19, 19, 19,
		10, 0, 0, -50, -100, 4000
	};

	uf_sort_quick(tab, sizeof(tab) / sizeof(tab[0]));
	assert_true(check_order(tab, sizeof(tab) / sizeof(tab[0])));
	(void)state;
}

static void
merge(void **state) {
	int	tab[] = {
		10, 46, 76, 1, 5, 23, 6, -19, 19, 19,
		10, 0, 0, -50, -100, 4000
	};

	uf_sort_merge(tab, sizeof(tab) / sizeof(tab[0]));
	assert_true(check_order(tab, sizeof(tab) / sizeof(tab[0])));
	(void)state;
}

static void
counting(void **state) {
	int	tab[] = {
		10, 46, 76, 1, 5, 23, 6, -19, 19, 19,
		10, 0, 0, -50, -100, 4000
	};

	uf_sort_counting(tab, sizeof(tab) / sizeof(tab[0]));
	assert_true(check_order(tab, sizeof(tab) / sizeof(tab[0])));
	(void)state;
}

int
main(int argc, char const** argv) {
	const struct CMUnitTest	test[] = {
		cmocka_unit_test(bubble),
		cmocka_unit_test(shell),
		cmocka_unit_test(quick),
		cmocka_unit_test(merge),
		cmocka_unit_test(counting),
	};

	(void)argc;
	(void)argv;
	return (cmocka_run_group_tests(test, 0, 0));
}
