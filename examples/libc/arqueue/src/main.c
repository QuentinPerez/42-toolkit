/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2014/06/30 02:04:22 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <arqueue/s_arqueue.h>
#include <f_string/f_print.h>
#include <stdio.h>

typedef struct	s_foo
{
	int	a;
	int	b;
	int	c;
}				t_foo;

int		main(int argc, char const** argv)
{
	t_arqueue	arqueue;
	t_foo		foo;
	t_foo		*bar;
	int			i;

	i = 0;
	D_ARQUEUE(init)(&arqueue, sizeof(t_foo), 5);
	while (i < 5)
	{
		foo.a = i;
		foo.b = i + 20;
		foo.c = i + 30;
		if (D_ARQUEUE(push)(&arqueue, &foo) == true)
			dprintf(1, "push %d -> a.%d b.%d b.%d\n", i, foo.a, foo.b, foo.c);
		i = i + 1;
	}
	i = i - 1;
	dprintf(1, "\n");
	while (i >= 0)
	{
		if ((bar = D_ARQUEUE(pop)(&arqueue)) != NULL)
		{
			dprintf(1, "pop %d -> a.%d b.%d b.%d\n", i, bar->a, bar->b, bar->c);
		}
		i = i - 1;
	}
	D_ARQUEUE(destroy)(&arqueue);
	(void)argc;
	(void)argv;
	return (0);
}

