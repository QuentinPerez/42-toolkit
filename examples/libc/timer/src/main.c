/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/16 12:55:00 by qperez            #+#    #+#             */
/*   Updated: 2014/03/19 15:12:00 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <timer/s_timer.h>
#include <f_string/f_print.h>

/*
 * This file is a little example of the t_timer structure
 */

/*
 * This tools is useless ...
 * No not when you want know "Who has the biggest"
 */

int	main(int argc, char const** argv)
{
	t_ui	i;
	t_ui	j;
	t_timer	timer;

	i = 0;
	/*
	 * Initialize timer
	 * Ok but initialize what ?
	 * I don't know
	 */
	D_TIMER(start)(&timer);
	/*
	 * BEWARE here you will see a bad code totally useless
	 * 3
	 * 2
	 * 1
	 * sorry for this
	 */
	while (i < 0xfffffff)
	{
		j = i * i * i;
		j = j * j * i;
		j = j * i;
		i = i + 1;
	}
	D_TIMER(pause)(&timer);
	/*
	 * Get time
	 * ...
	 * Who has the biggest ?
	 */
	uf_print_variadic("Loop in %d milliseconds\n", D_TIMER(get_ticks)(&timer));
	(void)argc;
	(void)argv;
	return (0);
}

