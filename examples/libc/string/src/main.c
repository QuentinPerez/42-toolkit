/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/22 12:40:41 by qperez            #+#    #+#             */
/*   Updated: 2013/10/25 11:15:51 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string/s_string.h>

int	main(int argc, char const** argv)
{
	t_string	string;

	D_STRING(init)(&string, 0);
	D_STRING(print_memory)(&string, "Client Buffer");
	D_STRING(print)(&string);
	D_STRING(destroy)(&string);
	(void)argc;
	(void)argv;
	return (0);
}

