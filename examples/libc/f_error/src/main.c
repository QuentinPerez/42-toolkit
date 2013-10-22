/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 16:40:56 by qperez            #+#    #+#             */
/*   Updated: 2013/10/22 18:29:23 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_error/m_error.h>
#include <stdio.h>

void	*uf_test_return_function_pointer(void)
{
	void	*(*why)();

	why = &uf_test_return_function_pointer;
	return (void*)(m_error("I return function pointer", (size_t)why));
}

void	*uf_test_return_addr(void)
{
	char	c;
	char	*why;

	why = &c;
	return (void*)(m_error("I return addr", (size_t)why));
}

int		uf_test_return_negative_value(void)
{
	return (m_error("I return -1", -1));
}

int		uf_test_return_value(void)
{
	return (m_error("I return 1", 1));
}

void	uf_test_return_in_function_void(void)
{
	return (m_error_v("I m void"));
}

int		main(int argc, const char **argv)
{
#ifndef	D_ERRORS_ON
	printf("\nIt's better with debug flags use 'make debug'\n\n");
#endif
	printf("\n== Return with different value ==\n");
	printf("\nI receive %d\n----\n", uf_test_return_value());
	printf("\nI receive negative number %d\n----\n", uf_test_return_negative_value());
	printf("\nI receive addr %p\n----\n", uf_test_return_addr());
	printf("\nI receive function pointer %p\n", uf_test_return_function_pointer());
	printf("\n== Return in function void ==\n");
	uf_test_return_in_function_void();
	printf("\n\n== Function infos ==\n");
	m_infos("42 school");
	(void)argv;
	(void)argc;
	return (0);
}
