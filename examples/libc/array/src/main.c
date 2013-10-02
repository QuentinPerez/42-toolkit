/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2013/10/02 13:32:15 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/s_array.h>
#include <stddef.h>

int		main(int argc, char const** argv)
{
	t_array array;

	D_ARRAY(init)(&array, NULL, NULL, 1);
	D_ARRAY(destroy)(&array);
	(void)argc;
	(void)argv;
	return (0);
}

