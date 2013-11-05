/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 13:26:45 by qperez            #+#    #+#             */
/*   Updated: 2013/11/04 20:37:49 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_memory/f_memory.h>
#include <f_string/f_print.h>

/*
 * This file is a little example of memory functions
 */

int		main(int argc, char const** argv)
{
	char	mem[50];

	/*
	 * Fill mem with 'A'
	 */
	uf_memset(mem, 'A', sizeof(*mem) * 50);
	/*
	 * Copy memory
	 */
	uf_memcpy(mem, "Hello 42", 8);
	/*
	 * Show memory
	 */
	uf_print_memory(mem, sizeof(*mem) * 50);
	(void)argc;
	(void)argv;
	return (0);
}

