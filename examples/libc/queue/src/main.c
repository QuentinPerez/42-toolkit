/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2013/09/30 11:49:40 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <queue/s_queue.h>
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
	t_queue	queue;

	D_QUEUE(init)(&queue, &uf_print);
	D_QUEUE(destroy)(&queue);
	(void)argc;
	(void)argv;
	return (0);
}

