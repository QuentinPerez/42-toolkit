/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2014/12/04 12:10:05 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdnotify/s_fdnotify.h>
#include <fdnotify/s_fdnotify_cell.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_demo
{
	t_fdnotify_cell	notif_cell; /*always the first menber */
	int				nop;
	int				nop2;
	int				nop3;
}				t_demo;

int		main(int argc, char const** argv)
{
	t_fdnotify			notif;
	t_list				list;
	t_demo				demo;
	t_fdnotify_event	event;
	char				str[10];
	ssize_t				nread;
	int					interaction;
	int					rep;

	rep = 4;
	demo.nop = 1;
	demo.nop2 = 2;
	demo.nop3 = 3;
	D_FDNOTIFY_CELL(init)(&demo.notif_cell, 0); /* 0 == stdin */
	D_LIST(init)(&list, NULL);
	if (D_LIST(push_back)(&list, &demo) == false)
	{
		dprintf(2, "Error List\n");
		return (1);
	}
	D_FDNOTIFY(init)(&notif);
	D_FDNOTIFY(enable_timeout)(&notif, 1, 0);
	while (D_FDNOTIFY(get_event)(&notif, &event, &list, &interaction) == true && rep > 0)
	{
		dprintf(1, "interaction [%d] ", interaction);
		if (event.v_type == e_fdnotify_read)
		{
			nread = read(0, str, 9);
			if (nread > 0)
			{
				str[nread - 1] = 0; /* delete \n */
				dprintf(1, "string -> [%s] data->nop %d, data->nop2 %d, data->nop3 %d\n", str, ((t_demo *)event.v_data)->nop, ((t_demo *)event.v_data)->nop2, ((t_demo *)event.v_data)->nop3);
			}
		}
		else if (interaction == 0)
			dprintf(1, "timeout\n");
		rep = rep - 1;
	}
	D_LIST(destroy)(&list);
	(void)argc;
	(void)argv;
	return (0);
}
