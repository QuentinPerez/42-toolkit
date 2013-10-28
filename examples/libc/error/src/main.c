/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/13 12:58:04 by qperez            #+#    #+#             */
/*   Updated: 2013/10/28 13:04:10 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <error/s_error.h>

bool	uf_test_bool(t_error *v_this)
{
	return (D_ERROR(add)(v_this, true, "return true"));
}

void	uf_test_void(t_error *v_this)
{
	return (D_ERROR(add_v)(v_this, "return void"));
}

int	main(int argc, char const** argv)
{
	t_error	error;

	if (D_ERROR(init)(&error, "file.txt") == false)
	{
		printf("Error\n");
		return (-1);
	}
	uf_test_void(&error);
	uf_test_bool(&error);
	D_ERROR(destroy)(&error);
	(void)argc;
	(void)argv;
	return (0);
}
