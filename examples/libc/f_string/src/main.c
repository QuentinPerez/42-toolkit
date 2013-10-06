/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 18:08:55 by qperez            #+#    #+#             */
/*   Updated: 2013/10/06 22:42:33 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_string/f_print.h>
#include <f_string/f_string.h>
#include <f_memory/f_memory.h>
#include <stdio.h>

#include <string.h>

int	main(int argc, const char **argv)
{
	char	dest[50];

	uf_memset(dest, '\0', sizeof(dest));
	uf_print_str("Copy Hello to dest\n");
	uf_strcpy(dest, "Hello\n");
	uf_print_str(dest);
	uf_memset(dest, '\0', sizeof(dest));
	uf_print_str("Copy 2 first byte of 42-toolkit\n");
	uf_strncpy(dest, "42-toolkit", 2);
	uf_print_str(dest);
	uf_print_str("\nAdd -tool\n");
	uf_strcat(dest, "-tool");
	uf_print_str(dest);
	uf_print_str("\nAdd kit\n");
	uf_strncat(dest, "kitfoobar", 3);
	uf_print_str(dest);
	(void)argv;
	(void)argc;
	return (0);
}
