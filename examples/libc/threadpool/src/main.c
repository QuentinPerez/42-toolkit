/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/05 13:40:15 by qperez            #+#    #+#             */
/*   Updated: 2014/07/05 19:26:05 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <threadpool/s_threadpool.h>
#include <stdio.h>
#include <unistd.h>

void	uf_hello(void *data)
{
	(void)data;
	dprintf(1, "Hello ");
}

void	uf_world(void *data)
{
	(void)data;
	dprintf(1, "World\n");
}

int	main(int argc, const char **argv)
{
	t_threadpool		pool;
	t_threadpool_task	task;

	task.f_funct = uf_hello;
	task.v_data = NULL;
	if (D_THREADPOOL(init)(&pool, 10) == false)
		return (1);
	D_THREADPOOL(add_task)(&pool, &task);
	task.f_funct = uf_world;
	D_THREADPOOL(add_task)(&pool, &task);
	sleep(1);
	D_THREADPOOL(destroy)(&pool);
	(void)argc;
	(void)argv;
	return (0);
}

