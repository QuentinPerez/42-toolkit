/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/18 17:29:39 by qperez            #+#    #+#             */
/*   Updated: 2013/10/18 17:39:03 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_crypto/f_crypto.h>
#include <f_string/f_string.h>
#include <f_string/f_str_tools.h>
#include <f_string/f_print.h>
#include <f_error/m_error.h>
#include <stdlib.h>

void	uf_check_equal_str(const char *expected, const char *current);
void	tf_test_crypto_xor(void);
void	tf_test_crypto_rot(void);
void	tf_check_rot(void (*fn)(char *), const char *org, const char *expected);

int		main(int argc, char const** argv)
{
	tf_test_crypto_xor();
	tf_test_crypto_rot();
	(void)argc;
	(void)argv;
	return (0);
}

void	uf_check_equal_str(const char *expected, const char *current)
{
	if (uf_strcmp(expected, current) == 0)
		uf_print_str("\e[32mOK\e[0m\n");
	else
	{
		uf_print_str("\e[31mFAIL\e[0m: [");
		uf_print_str(expected);
		uf_print_str("] != [");
		uf_print_str(current);
		uf_print_str("]\n");
	}
}

void	tf_test_crypto_xor(void)
{
	char	*data;

	data = uf_strdup("Hello 42\n");
	m_infos("Test XOR");
	uf_print_str(data);
	uf_crypto_xor(data, "KEYS", uf_str_len(data));
	uf_print_str("Version crypter [");
	uf_print_str(data);
	uf_print_str("]\n");
	uf_crypto_xor(data, "KEYS", uf_str_len(data));
	uf_print_str(data);
	free(data);
}

void	tf_test_crypto_rot(void)
{
	m_infos("Test ROT5");
	tf_check_rot(&uf_crypto_rot5, "Hello 42!", "Hello 97!");
	m_infos("Test ROT13");
	tf_check_rot(&uf_crypto_rot13, "Hello 42!", "Uryyb 42!");
	m_infos("Test ROT18");
	tf_check_rot(&uf_crypto_rot18, "Hello 42!", "Uryyb 97!");
	m_infos("Test ROT47");
	tf_check_rot(&uf_crypto_rot47, "Hello 42!", "w6==@ caP");
}

void	tf_check_rot(void (*fn)(char *), const char *org, const char *expected)
{
	char	*str;

	str = uf_strdup(org);
	fn(str);
	uf_check_equal_str(expected, str);
	fn(str);
	uf_check_equal_str(org, str);
	free(str);
}
