/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/05 13:40:15 by qperez            #+#    #+#             */
/*   Updated: 2015/06/09 14:25:33 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <threadpool/s_threadpool.h>
#include <threadpool/s_barrier.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

t_barrier	barrier;

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

void	*uf_test_barrier(void *arg)
{
	D_BARRIER(wait)(&barrier);
	dprintf(1, "thread %u\n", (unsigned int)(uintptr_t)arg);
	return (NULL);
}

int	main(int argc, const char **argv)
{
	t_threadpool		pool;
	t_threadpool_task	task;
	const unsigned int	nb_thread = 10;
	pthread_t			th[nb_thread];
	uintptr_t			i = 0;
	unsigned int		j = 0;

	task.f_funct = uf_hello;
	task.v_data = NULL;
	if (D_THREADPOOL(init)(&pool, 10) == false)
		return (1);
	D_THREADPOOL(add_task)(&pool, &task);
	task.f_funct = uf_world;
	D_THREADPOOL(add_task)(&pool, &task);
	sleep(1);
	D_THREADPOOL(destroy)(&pool);

	D_BARRIER(init)(&barrier, nb_thread);
	while (i < nb_thread) {
		pthread_create(&th[i], NULL, uf_test_barrier, (void*)i);
		i = i + 1;
	}
	while (j < nb_thread) {
		pthread_join(th[j], NULL);
		j = j + 1;
	}
	D_BARRIER(destroy)(&barrier);
	(void)argc;
	(void)argv;
	return (0);
}

