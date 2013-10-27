/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 16:40:56 by qperez            #+#    #+#             */
/*   Updated: 2013/10/27 17:25:54 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_error/m_error.h>
#include <stdio.h>

void	*uf_test_return_function_pointer(void)
{
	void	*(*why)();

	why = &uf_test_return_function_pointer;
	return (void*)(m_error((size_t)why, "I return function pointer"));
}

void	*uf_test_return_addr(void)
{
	char	c;
	char	*why;

	why = &c;
	return (void*)(m_error((size_t)why, "I return addr"));
}

int		uf_test_return_negative_value(void)
{
	return (m_error(-1, "I return -1"));
}

int		uf_test_return_value(void)
{
	return (m_error(1, "I return 1"));
}

void	uf_test_return_in_function_void(void)
{
	return (m_error_v("I m void"));
}

int		main(int argc, const char **argv)
{
	printf("\n== Return with different value ==\n");
	printf("\nI receive %d\n----\n", uf_test_return_value());
	printf("\nI receive negative number %d\n----\n", uf_test_return_negative_value());
	printf("\nI receive addr %p\n----\n", uf_test_return_addr());
	printf("\nI receive function pointer %p\n", uf_test_return_function_pointer());
	printf("\n== Return in function void ==\n");
	uf_test_return_in_function_void();
	printf("\n\n== Function infos ==\n");
	m_infos("%d school", 42);
	(void)argv;
	(void)argc;
	return (0);
}
