/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/16 12:55:00 by qperez            #+#    #+#             */
/*   Updated: 2013/10/16 13:01:39 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <timer/s_timer.h>
#include <f_string/f_print.h>

int	main(int argc, char const** argv)
{
	ui		i;
	ui		j;
	t_timer	timer;

	i = 0;
	D_TIMER(start)(&timer);
	while (i < 0xfffffff)
	{
		j = i * i * i;
		j = j * j * i;
		j = j * i;
		i = i + 1;
	}
	D_TIMER(pause)(&timer);
	uf_print_str("Loop in ");
	uf_print_nbr(D_TIMER(get_ticks)(&timer));
	uf_print_str(" milliseconds\n");
	(void)argc;
	(void)argv;
	return (0);
}

