/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/05 15:08:40 by qperez            #+#    #+#             */
/*   Updated: 2013/10/07 11:59:26 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list/s_list.h>
#include <f_string/f_print.h>

bool	uf_print_value(void *data)
{
	uf_print_str("Value : ");
	uf_print_nbr((size_t)data);
	uf_print_char('\n');
	return (true);
}


int	main(int argc, char const** argv)
{
	t_list	list;
	size_t	i;

	i = 0;
	D_LIST(init)(&list, NULL);
	while (i < 5)
	{
		uf_print_str("Push back : ");
		uf_print_nbr(i);
		uf_print_char('\n');
		D_LIST(push_back)(&list, (void *)i);
		i = i + 1;
	}
	D_LIST(insert)(&list, D_LIST(end)(&list)->v_next, (void*)-1);
	D_LIST(print_addr)(&list);
	D_LIST(foreach)(&list, uf_print_value);
	D_LIST(destroy)(&list);
	(void)argc;
	(void)argv;
	return (0);
}

