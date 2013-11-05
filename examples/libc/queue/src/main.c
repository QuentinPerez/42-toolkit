/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2013/11/04 21:09:53 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <queue/s_queue.h>
#include <f_string/f_print.h>

/*
 * This file is a little example of the t_aueue structure
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
	t_queue	queue;

	i = 0;
	/*
	 * Initialize with NULL like list
	 */
	D_QUEUE(init)(&queue, NULL);
	while (i < 5)
	{
		/*
		 * Why i + 42 << i^2
		 * For fun he is crazy
		 */
		D_QUEUE(push)(&queue, (void*)i + (42 << (i * i)));
		i = i + 1;
	}
	/*
	 * Print all cellule
	 */
	D_QUEUE(foreach)(&queue, &uf_print);
	uf_print_char('\n');
	/*
	 * And yes I freeing memory
	 */
	D_QUEUE(destroy)(&queue);
	(void)argc;
	(void)argv;
	return (0);
}

