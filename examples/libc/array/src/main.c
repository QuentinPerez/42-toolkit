/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2013/10/02 15:51:39 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_string/f_print.h>
#include <array/s_array.h>
#include <stddef.h>

typedef struct	s_point
{
	ui	x;
	ui	y;
	ui	z;
}				t_point;

bool	uf_print_point(void *data)
{
	t_point	*ptr;

	ptr = (t_point*)data;
	uf_print_str("Point -> x : ");
	uf_print_nbr(ptr->x);
	uf_print_str(" y : ");
	uf_print_nbr(ptr->y);
	uf_print_str(" z : ");
	uf_print_nbr(ptr->z);
	uf_print_char('\n');
	return (true);
}

int		main(int argc, char const** argv)
{
	ui		i;
	t_array array;
	t_point	point;

	i = 0;
	D_ARRAY(init)(&array, NULL, NULL, sizeof(t_point));
	while (i < 10)
	{
		point.x = i + 2;
		point.y = i + 4;
		point.z = i + 8;
		D_ARRAY(push_back)(&array, &point);
		i = i + 1;
	}
	D_ARRAY(foreach)(&array, uf_print_point);
	D_ARRAY(destroy)(&array);
	(void)argc;
	(void)argv;
	return (0);
}

