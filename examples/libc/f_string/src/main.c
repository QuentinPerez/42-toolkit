/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 18:08:55 by qperez            #+#    #+#             */
/*   Updated: 2015/04/19 14:09:36 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_string/f_print.h>
#include <f_string/f_string.h>
#include <f_memory/f_memory.h>
#include <stdlib.h>
#include <sys/mman.h>

/*
 * This file is a little example of string function
 */

/*
 * If you see more ... the way is f_string/f_string.h
 */

int	main(int argc, const char **argv)
{
	char	*ptr;
	size_t	len;

	/*
	 * Look f_string header for more functions
	 */
	uf_print_variadic("%s %d, hexa version %X ,"
					  "%egreen%E red bold%e%c", "Hello",
					   42, 42, 32, 31, 0, '\n');
	if ((ptr = uf_mapfile("./f_string/src/main.c", &len,
		PROT_READ | PROT_WRITE, true)) != NULL)
	{
		write(1, ptr, len);
		if (uf_unmapfile(ptr, len) != true)
			return (1);
	}
	(void)argv;
	(void)argc;
	return (0);
}
