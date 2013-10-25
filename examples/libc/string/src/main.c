/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/22 12:40:41 by qperez            #+#    #+#             */
/*   Updated: 2013/10/25 20:18:04 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_string/f_print.h>
#include <string/s_string.h>

int	main(int argc, char const** argv)
{
	t_string	string;

	D_STRING(init)(&string, 0);
	D_STRING(add_str)(&string, "Hello ");
	D_STRING(add_nbr)(&string, 42);
	D_STRING(add_char)(&string, ' ');
	D_STRING(add_ptr)(&string, (void*)0xdeadbff);
	D_STRING(add_char)(&string, '\n');
	D_STRING(add_nstr)(&string, "Good bye\nhide", 9);
	D_STRING(variadic)(&string, "Test %d Variad %s\n", 13, "Change life");
	D_STRING(variadic)(&string, "42 to hexbase %x, ptr %p\n", 42, (void*)0xdeadbff);
	D_STRING(print_memory)(&string, "Client Buffer");
	D_STRING(print)(&string);
	D_STRING(destroy)(&string);
	(void)argc;
	(void)argv;
	return (0);
}

