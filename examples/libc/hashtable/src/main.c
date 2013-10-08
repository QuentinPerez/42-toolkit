/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/08 13:01:24 by qperez            #+#    #+#             */
/*   Updated: 2013/10/08 20:54:57 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <hashtable/s_htable.h>
#include <f_string/f_print.h>


bool	uf_print_value(t_htable_cell *cell)
{
	uf_print_nbr((size_t)cell->v_data);
	uf_print_char(' ');
	return (true);
}

int	main(int argc, char const** argv)
{
	t_htable	htable;

	D_HTABLE(init)(&htable, 71, NULL);
	D_HTABLE(add)(&htable, "hello", (void*)1);
	D_HTABLE(add)(&htable, "men", (void*)2);
	D_HTABLE(add)(&htable, "born", (void*)3);
	D_HTABLE(add)(&htable, "2", (void*)4);
	D_HTABLE(add)(&htable, "code", (void*)5);
	D_HTABLE(add)(&htable, "november", (void*)6);
	D_HTABLE(add)(&htable, "42", (void*)7);
	D_HTABLE(add)(&htable, "paris", (void*)8);
	D_HTABLE(add)(&htable, "school", (void*)9);
	D_HTABLE(print)(&htable, uf_print_value);
	D_HTABLE(destroy)(&htable);
	(void)argc;
	(void)argv;
	return (0);
}

