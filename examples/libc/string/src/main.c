/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/22 12:40:41 by qperez            #+#    #+#             */
/*   Updated: 2013/10/25 14:38:26 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_string/f_print.h>
#include <string/s_string.h>

int	main(int argc, char const** argv)
{
	ui			i;
	t_string	string;

	D_STRING(init)(&string, 0);
	i = 0;
	while (i < 4)
	{
		D_STRING(add_str)(&string, "Hello\n");
		i = i + 1;
	}
	D_STRING(print_memory)(&string, "Client Buffer");
	D_STRING(print)(&string);
	D_STRING(destroy)(&string);
	(void)argc;
	(void)argv;
	return (0);
}

