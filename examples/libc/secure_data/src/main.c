/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/13 12:58:04 by qperez            #+#    #+#             */
/*   Updated: 2015/04/19 13:40:47 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <secure_data/s_secure_data.h>

int		main(int argc, char const** argv)
{
	t_secure_data	sdata;

	/*
	 * Initialize the structure
	 */
	if (D_SECURE_DATA(init)(&sdata) == false)
	{
		printf("Error\n");
		return (-1);
	}
	D_SECURE_DATA(destroy)(&sdata);
	(void)argc;
	(void)argv;
	return (0);
}
