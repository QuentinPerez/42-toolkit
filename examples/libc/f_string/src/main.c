/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 18:08:55 by qperez            #+#    #+#             */
/*   Updated: 2013/11/04 20:48:48 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_string/f_print.h>
#include <f_string/f_string.h>
#include <f_memory/f_memory.h>
#include <stdlib.h>

/*
 * This file is a little example of string function
 */

/*
 * If you see more ... the way is f_string/f_string.h
 */

int	main(int argc, const char **argv)
{
	/*
	 * Why one function ?
	 * Because this function call sub-function so if you are interest
	 * look f_string header
	 *
	 * And RTFM :|
	 */
	uf_print_variadic("%s %d, hexa version %X ,"
					  "%egreen%E red bold%e%c", "Hello",
					   42, 42, 32, 31, 0, '\n');
	(void)argv;
	(void)argc;
	return (0);
}
