/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/05 15:08:40 by qperez            #+#    #+#             */
/*   Updated: 2014/12/02 13:12:10 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector/s_vector.h>
#include <stdlib.h>
#include <f_string/f_print.h>

static bool	uf_print(void *ptr)
{
	uf_print_str("Value : ");
	uf_print_nbr((size_t)ptr);
	uf_print_char('\n');
	return (true);
}

/*
 * This file is a little example of the t_vector structure
 */

/*
 * Nostalgie moment:
 * It's the first of Lib42
 */

int	main(int argc, char const** argv)
{
	size_t		i;
	t_vector	vector;

	/*
	 * Initialize vector
	 */
	i = 1;
	D_VECTOR(init)(&vector, NULL, NULL);
	while (i < 3)
	{
		/*
		 * Add data without check return value MUAHAHAHA
		 */
		D_VECTOR(push_back)(&vector, (void *)(size_t)i);
		i = i + 1;
	}
	/*
	 * Print all value
	 */
	D_VECTOR(foreach)(&vector, &uf_print);
	/*
	 * See you later memory
	 */
	D_VECTOR(destroy)(&vector);
	(void)argc;
	(void)argv;
	return (0);
}

