/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 13:26:45 by qperez            #+#    #+#             */
/*   Updated: 2014/10/29 10:22:24 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_memory/f_memory.h>
#include <f_string/f_print.h>

/*
 * This file is a little example of memory functions
 */

int		main(int argc, char const** argv)
{
	char	data[256];
	int		i;

	i = 0;
	while (i < 256)
	{
		data[i] = i;
		i = i + 1;
	}
	uf_print_memory(data, sizeof(data));
	uf_memset(data, 0, sizeof(data));
	uf_memcpy(data, "AAAAAAAA", 8);
	uf_print_char('\n');
	uf_memcpy(data + 50, "AAAAAAAA", 8);
	uf_print_memory(data, sizeof(data));
	(void)argc;
	(void)argv;
	return (0);
}

