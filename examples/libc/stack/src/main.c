/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2013/10/03 14:44:24 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stack/s_stack.h>
#include <f_string/f_print.h>

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

	i = 0;
	D_STACK(init)(&stack, NULL);
	while (i < 5)
	{
		D_STACK(push)(&stack, (void*)i);
		i = i + 1;
	}
	D_STACK(foreach)(&stack, &uf_print);
	uf_print_char('\n');
	D_STACK(destroy)(&stack);
	(void)argc;
	(void)argv;
	return (0);
}

