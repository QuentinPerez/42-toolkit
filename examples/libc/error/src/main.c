/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/13 12:58:04 by qperez            #+#    #+#             */
/*   Updated: 2013/09/13 14:12:54 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <error/s_error.h>

int	main(int argc, char const** argv)
{
	t_error	error;

	if (D_ERROR(init)(&error, "file.txt") == false)
	{
		printf("Error\n");
		return (-1);
	}
	D_ERROR(add)(&error, "test 1");
	D_ERROR(add)(&error, "test 2");
	D_ERROR(destroy)(&error);
	(void)argc;
	(void)argv;
	return (0);
}
