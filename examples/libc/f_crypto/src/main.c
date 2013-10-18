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
#include <stdlib.h>

int	main(int argc, char const** argv)
{
	char	*data;

	data = uf_strdup("Hello 42\n");
	uf_print_str(data);
	uf_crypto_xor(data, "KEYS", uf_str_len(data));
	uf_print_str("Version crypter [");
	uf_print_str(data);
	uf_print_str("]\n");
	uf_crypto_xor(data, "KEYS", uf_str_len(data));
	uf_print_str(data);
	free(data);
	(void)argc;
	(void)argv;
	return (0);
}

