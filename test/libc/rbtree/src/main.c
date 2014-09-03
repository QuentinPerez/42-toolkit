/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2014/09/03 17:49:48 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_string/f_print.h>
#include <rbtree/s_rbtree.h>
#include <unit/s_unit.h>

int		uf_rbcmp(void *d1, void *d2)
{
	return ((size_t)d1 - (size_t)d2);
}

bool	uf_print(void *d1, void *d2)
{
	uf_print_nbr((size_t)d1);
	uf_print_char(' ');
	(void)d2;
	return (true);
}

void	D_UNIT_FUNCT(memleaks)
{
	size_t		i;
	t_rbtree	rbtree;

	D_RBTREE(init)(&rbtree, uf_rbcmp, 0);
	i = 0;
	while (i < 30)
	{
		D_RBTREE(insert)(&rbtree, (void*)i);
		i = i + 1;
	}
	D_RBTREE(destroy)(&rbtree);
	(void)t;
}

int		main(int argc, char const** argv)
{
	t_unit	unit;

	D_UNIT(init)(&unit);
	D_UNIT(add_context)(&unit, "Leaks", 0, 0);
	D_UNIT(add_test)(&unit, "Leaks", memleaks);
	D_UNIT(console_run)(&unit);
	D_UNIT(destroy)(&unit);
	(void)argc;
	(void)argv;
	return (0);
}
