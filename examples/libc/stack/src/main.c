/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2013/11/04 21:11:50 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stack/s_stack.h>
#include <f_string/f_print.h>

/*
 * This file is a little example of the t_stack structure
 */

bool	uf_print(void *data)
{
	uf_print_nbr((size_t)data);
	uf_print_char(' ');
	return (true);
}

int		main(int argc, char const** argv)
{
	size_t	i;
	t_stack	stack;

	/*
	 * Like queue so cf:queue
	 */
	i = 0;
	D_STACK(init)(&stack, NULL);
	while (i < 5)
	{
		D_STACK(push)(&stack, (void*)i + (42 << (i * (i + 1))));
		i = i + 1;
	}
	D_STACK(foreach)(&stack, &uf_print);
	uf_print_char('\n');
	D_STACK(destroy)(&stack);
	(void)argc;
	(void)argv;
	return (0);
}

