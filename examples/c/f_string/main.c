/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 18:08:55 by qperez            #+#    #+#             */
/*   Updated: 2013/08/28 18:21:38 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_print_fd.h>
#include <stdio.h>

#define	D_TEST(funct, param)	printf("== "#funct" ==\n"); funct(param, 1)

int	main(int argc, const char **argv)
{
	(void)argc;
	(void)argv;
	D_TEST(uf_print_str_fd, "Hello World\n");
	D_TEST(uf_print_nbr_fd, 42);
	uf_print_char_fd('\n', 1);
	D_TEST(uf_print_char_fd, '!');
	uf_print_char_fd('\n', 1);
	return (0);
}
