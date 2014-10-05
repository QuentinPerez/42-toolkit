/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/13 12:58:04 by qperez            #+#    #+#             */
/*   Updated: 2014/10/05 13:35:31 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <rand/s_rand.h>

int		main(int argc, char const** argv)
{
	t_rand	rand_fd;
	t_rand	rand_std;

	/*
	 * Initialize the structure
	 */
	if (D_RAND(init)(&rand_fd, e_rand_file) == false
		|| D_RAND(init)(&rand_std, e_rand_std) == false)
	{
		printf("Error\n");
		return (-1);
	}
	printf("/dev/urandom %zd\n", D_RAND(generate)(&rand_fd));
	printf("libc         %zd\n", D_RAND(generate)(&rand_std));
	D_RAND(destroy)(&rand_fd);
	D_RAND(destroy)(&rand_std);
	(void)argc;
	(void)argv;
	return (0);
}
