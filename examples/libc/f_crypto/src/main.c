/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/18 17:29:39 by qperez            #+#    #+#             */
/*   Updated: 2013/11/04 20:28:43 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_crypto/f_crypto.h>
#include <f_memory/f_memory.h>
#include <f_string/f_print.h>
#include <f_string/f_string.h>

/*
 * This file is a little example crypto functions
 */

int		main(int argc, char const** argv)
{
	char	dest[50];

	/*
	 * Cleaning before everything ... .. .
	 */
	uf_memset(dest, 0, sizeof(*dest) * 50);
	/*
	 * Copying msg to dest
	 */
	uf_strcpy(dest, "The president is not dead, for the moment");
	uf_print_variadic("Msg : %s\n", dest);
	/*
	 * Use xor algorthym to encrypt msg ...
	 */
	uf_print_str("Xor Power\n");
	uf_crypto_xor(dest, (const unsigned char *)"01/10/1110", sizeof(*dest) * 50);
	uf_print_variadic("Encrypt Msg : %s\n", dest);
	/*
	 * Reuse xor algorthym to decrypt msg
	 */
	uf_crypto_xor(dest, (const unsigned char *)"01/10/1110", sizeof(*dest) * 50);
	uf_print_variadic("Decrypt Msg : %s\n", dest);
	/*
	 * Now use a rot algorithym the 13
	 */
	uf_print_str("Rot Power\n");
	uf_crypto_rot13(dest);
	uf_print_variadic("Encrypt Msg : %s\n", dest);
	uf_crypto_rot13(dest);
	uf_print_variadic("Decrypt Msg : %s\n", dest);
	(void)argc;
	(void)argv;
	return (0);
}
