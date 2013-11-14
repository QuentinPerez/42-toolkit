/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/13 12:58:04 by qperez            #+#    #+#             */
/*   Updated: 2013/11/14 18:54:47 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rbtree/s_rbtree.h>
#include <f_string/f_print.h>
#include <unistd.h>

int		uf_rbcmp(void *d1, void *d2)
{
	return ((int)d1 - (int)d2);
}

bool	uf_print(void *d1, void *d2)
{
	uf_print_nbr((int)d1);
	uf_print_char(' ');
	(void)d2;
	return (true);
}

int		main(int argc, char const** argv)
{
	size_t			i;
	t_rbtree	rbtree;

	/*
	 * Initialize the structure rbtree
	 */
	D_RBTREE(init)(&rbtree, uf_rbcmp, 0);
	i = 0;
	while (i < 30)
	{
		/*
		 * Insert number i
		 */
		D_RBTREE(insert)(&rbtree, (void*)i);
		i = i + 1;
	}
	/*
	 * Print all value
	 */
	D_RBTREE(foreach_in)(&rbtree, uf_print, 0);
	/*
	 * free memory
	 */
	D_RBTREE(destroy)(&rbtree);
	(void)argc;
	(void)argv;
	return (0);
}
