/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/05 15:08:40 by qperez            #+#    #+#             */
/*   Updated: 2014/12/02 13:11:57 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list/s_list.h>
#include <f_string/f_print.h>
#include <stddef.h>

/*
 * This file is a little example of the t_list structure
 */

bool	uf_print_data(void *data)
{
	uf_print_variadic("Data = %d\n", (size_t)data);
	return (true);
}

int		main(int argc, char const** argv)
{
	t_list	list;

	/*
	 * Initialize with delete pointer NULL because my data it's not allocated
	 */
	D_LIST(init)(&list, NULL);
	/*
	 * Push at the end, the data 101
	 * Check return Value ?
	 * No it's useless ! Ok Master
	 */
	D_LIST(push_back)(&list, (void *)101);
	D_LIST(push_back)(&list, (void *)11101);
	D_LIST(foreach)(&list, uf_print_data);
	/*
	 * We free memory ?
	 * Well ... let it and we'll see
	 */
	D_LIST(destroy)(&list);
	(void)argc;
	(void)argv;
	return (0);
}
