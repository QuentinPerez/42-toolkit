/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2013/11/05 16:47:03 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <getopt/s_getopt.h>

int		main(int argc, char const** argv)
{
	t_getopt	getopt;

	D_GETOPT(init)(&getopt, argc, argv,
				   "q:w:e:R:qwe:Qw:dqW:DqWD:qwd:qwd:s:d:a:d");
	D_GETOPT(destroy)(&getopt);
	return (0);
}
