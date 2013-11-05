/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/22 12:40:41 by qperez            #+#    #+#             */
/*   Updated: 2013/11/04 21:15:54 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_string/f_print.h>
#include <string/s_string.h>

/*
 * This file is a little example of the t_string structure
 */

int	main(int argc, char const** argv)
{
	t_string	string;

	/*
	 * Initialize with NULL because I want OK !!!!
	 */
	D_STRING(init)(&string, 0);
	/*
	 * Like printf it's funny no ?
	 */
	D_STRING(variadic)(&string, "42 in hex %x, ptr %p\n", 42, (void*)0xdeadbff);
	/*
	 * Print memory like hexeditor
	 * For more skills bro
	 */
	D_STRING(print_memory)(&string, "Memory");
	/*
	 * Today I am nice boy
	 * So I free the memory
	 */
	D_STRING(destroy)(&string);
	(void)argc;
	(void)argv;
	return (0);
}
