/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2013/10/02 13:33:57 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <queue/s_queue.h>
#include <f_string/f_print.h>
#include <stddef.h>

bool	uf_print(void *data)
{
	uf_print_nbr((size_t)data);
	uf_print_char(' ');
	return (true);
}

int		main(int argc, char const** argv)
{
	ui		i;
	t_queue	queue;

	i = 0;
	D_QUEUE(init)(&queue, NULL);
	while (i < 5)
	{
		D_QUEUE(push)(&queue, (void*)i);
		i = i + 1;
	}
	D_QUEUE(foreach)(&queue, &uf_print);
	uf_print_char('\n');
	D_QUEUE(destroy)(&queue);
	(void)argc;
	(void)argv;
	return (0);
}

