/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/22 12:40:41 by qperez            #+#    #+#             */
/*   Updated: 2013/10/22 12:41:25 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string/s_string.h>

int	main(int argc, char const** argv)
{
	t_string	string;

	D_STRING(init)(&string, 0);
	D_STRING(destroy)(&string);
	(void)argc;
	(void)argv;
	return (0);
}

