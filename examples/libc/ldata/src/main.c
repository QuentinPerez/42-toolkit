/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/13 12:58:04 by qperez            #+#    #+#             */
/*   Updated: 2015/04/19 16:46:57 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ldata/s_ldata.h>
#include <string.h>
#include <stdio.h>

int		main(int argc, char const** argv)
{
	t_ldata	ldata;

	/*
	 * Initialize the structure
	 */
	if (D_LDATA(init)(&ldata, 10) == false)
	{
		printf("Error\n");
		return (-1);
	}
	strcpy((char *)D_LDATA(get_ptr)(&ldata), "Hello!");
	dprintf(1, "%s\n", (char *)D_LDATA(get_ptr)(&ldata));
	D_LDATA(destroy)(&ldata);
	(void)argc;
	(void)argv;
	return (0);
}
