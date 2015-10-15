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
#include <f_crypto/f_crypto.h>
#include <stdio.h>

static void
xor(void **state) {
	char alpha[] = "abcdefghijklmnopqrstuvwxyz";

	uf_crypto_xor(alpha, (const unsigned char *)"HELLO WORLD", sizeof(alpha));
	uf_crypto_xor(alpha, (const unsigned char *)"HELLO WORLD", sizeof(alpha));
	assert_string_equal(alpha, "abcdefghijklmnopqrstuvwxyz");
	(void)state;
}

static void
rot13(void **state) {
	char alpha[] = "abcdefghijklmnopqrstuvwxyz";

	uf_crypto_rot13(alpha);
	assert_string_equal(alpha, "nopqrstuvwxyzabcdefghijklm");
	(void)state;
}

static void
rot47(void **state) {
	char alpha[] = "abcdefghijklmnopqrstuvwxyz0123456789";

	uf_crypto_rot47(alpha);
	assert_string_equal(alpha, "23456789:;<=>?@ABCDEFGHIJK_`abcdefgh");
	(void)state;
}

static void
rot18(void **state) {
	char alpha[] = "abcdefghijklmnopqrstuvwxyz0123456789";

	uf_crypto_rot18(alpha);
	assert_string_equal(alpha, "nopqrstuvwxyzabcdefghijklm5678901234");
	(void)state;
}

static void
rot5(void **state) {
	char alpha[] = "0123456789";

	uf_crypto_rot5(alpha);
	assert_string_equal(alpha, "5678901234");
	(void)state;
}

static void
rot5_alpha(void **state) {
	char alpha[] = "abcdefghijklmnopqrstuvwxyz";

	uf_crypto_rot5(alpha);
	assert_string_equal(alpha, "abcdefghijklmnopqrstuvwxyz");
	(void)state;
}


int
main(int argc, char const** argv) {
	const struct CMUnitTest	test[] = {
		cmocka_unit_test(rot5),
		cmocka_unit_test(rot5_alpha),
		cmocka_unit_test(rot13),
		cmocka_unit_test(rot18),
		cmocka_unit_test(rot47),
		cmocka_unit_test(xor),
	};

	(void)argc;
	(void)argv;
	return (cmocka_run_group_tests(test, 0, 0));
}
