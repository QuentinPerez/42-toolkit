/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2013/09/27 17:38:19 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stack/s_stack.h>
#include <f_string/f_print.h>
#include <stddef.h>

void	uf_print(void *data)
{
	uf_print_str("Destroy : ");
	uf_print_nbr((size_t)data);
	uf_print_char('\n');
}

int		main(int argc, char const** argv)
{
	ui		i;
	t_stack	stack;

	D_STACK(init)(&stack, &uf_print);
	while (i < 5)
	{
		D_STACK(push)(&stack, (void*)i);
		i = i + 1;
	}
	uf_print_str("Top : ");
	uf_print_nbr((size_t)D_STACK(top)(&stack));
	uf_print_char('\n');
	D_STACK(destroy)(&stack);
	(void)argc;
	(void)argv;
	return (0);
}

