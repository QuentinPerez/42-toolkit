/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/08 13:01:24 by qperez            #+#    #+#             */
/*   Updated: 2014/08/27 10:39:34 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <htable/s_htable.h>
#include <f_string/f_print.h>


bool	uf_print_value(t_htable_cell *cell)
{
	uf_print_nbr((size_t)cell->v_data);
	uf_print_char(' ');
	return (true);
}

/*
 * This file is a little example of the t_htable structure
 */

int	main(int argc, char const** argv)
{
	t_htable	htable;

	/*
	 * 127 is prime number OK !!
	 */
	D_HTABLE(init)(&htable, 127, NULL, NULL);
	/*
	 * Here I add "42" in htable
	 * With data (void*)1;
	 * Because it's demonstration not the truth !
	 */
	D_HTABLE(add)(&htable, "42", (void*)7);
	D_HTABLE(add)(&htable, "paris", (void*)8);
	D_HTABLE(add)(&htable, "school", (void*)9);
	/*
	 * Print all table
	 */
	D_HTABLE(print)(&htable, uf_print_value);
	uf_print_variadic("The data assigned at 42 is %d\n", D_HTABLE(get)(&htable, "42"));
	/*
	 * Free memory again yes yes (wo)man !
	 */
	D_HTABLE(destroy)(&htable);
	(void)argc;
	(void)argv;
	return (0);
}
