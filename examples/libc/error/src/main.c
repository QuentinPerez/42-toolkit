/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/13 12:58:04 by qperez            #+#    #+#             */
/*   Updated: 2015/04/19 16:24:52 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <error/s_error.h>

bool	uf_test_bool(t_error *v_this)
{
	/*
	 * Use variadic here Are you kidding ?
	 * ...
	 * Ok just for the skills
	 */
	return (F_ERROR_ADD(v_this, true, "The %s error", "first"));
}

/*
 * This file is a little example of the t_error structure
 */

int		main(int argc, char const** argv)
{
	t_error	error;

	/*
	 * Initialize the structure with the filename here file.txt
	 */
	if (D_ERROR(init)(&error, "file.txt") == false)
	{
		printf("Error\n");
		return (-1);
	}
	/*
	 * Add 2 errors to file.txt
	 */
	uf_test_bool(&error);
	/*
	 * free memory used by array !!
	 * ...
	 * Pff it's useless the OS make it after
	 * ....
	 */
	D_ERROR(destroy)(&error);
	(void)argc;
	(void)argv;
	return (0);
}
