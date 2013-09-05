/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/05 15:08:40 by qperez            #+#    #+#             */
/*   Updated: 2013/09/05 15:14:30 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list/s_list.h>
#include <f_string/f_print.h>

void	uf_destroy_value(void *data)
{
	uf_print_str("Destroy : ");
	uf_print_nbr((int)data);
	uf_print_char('\n');
}


int	main(int argc, char const** argv)
{
	t_list	list;
	uint	i;

	i = 0;
	D_LIST(init)(&list, &uf_destroy_value);
	while (i < 5)
	{
		uf_print_str("Push back : ");
		uf_print_nbr(i);
		uf_print_char('\n');
		D_LIST(push_back)(&list, (void *)i);
		i = i + 1;
	}
	D_LIST(print_addr)(&list);
	D_LIST(destroy)(&list);
	(void)argc;
	(void)argv;
	return (0);
}

