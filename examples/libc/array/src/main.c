/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2013/11/04 20:51:56 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_string/f_print.h>
#include <f_memory/f_memory.h>
#include <array/s_array.h>

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

bool	uf_print_point(void *data)
{
	t_point	*point;

	point = (t_point *)data;
	uf_print_variadic("x: %d, y: %d\n", point->x, point->y);
	return (true);
}

bool	uf_cmp(void *d1, void *d2)
{
	return (uf_memcmp(d1, d2, sizeof(t_point)));
}

/*
 * This file is a little example of the t_array structure
 */

int		main(int argc, char const** argv)
{
	t_array array;
	t_point	point;

	/*
	 * initialize array with realloc and delete pointer NULL
	 * and sizeof structure t_point
	 */
	D_ARRAY(init)(&array, NULL, NULL, sizeof(t_point));
	/*
	 * add point to array ! Check return value not as me :| !
	 */
	point.x = 1;
	point.y = 2;
	uf_print_variadic("Push back x: %d, y: %d\n", point.x, point.y);
	D_ARRAY(push_back)(&array, &point);
	/*
	 * Check if array is empty
	 */
	uf_print_variadic("Array is empty ? %d\n", D_ARRAY(empty)(&array));
	/*
	 * Get size and capacity
	 */
	uf_print_variadic("Capacity %d, Size %d\n", D_ARRAY(capacity)(&array), D_ARRAY(size)(&array));
	/*
	 * Change capacity
	*/
	D_ARRAY(resize)(&array, 10);
	uf_print_variadic("Capacity %d, Size %d\n", D_ARRAY(capacity)(&array), D_ARRAY(size)(&array));
	/*
	 * Print contents
	 */
	D_ARRAY(foreach)(&array, uf_print_point);
	/*
	 * Get first element
	 */
	uf_print_point(F_ARRAY_AT(&array, 0, t_point *));
	/*
	 * Delete this fucking point !!
	 */
	uf_print_variadic("Delete point\n");
	D_ARRAY(delete_if)(&array, uf_cmp, &point);
	uf_print_variadic("Capacity %d, Size %d\n", D_ARRAY(capacity)(&array), D_ARRAY(size)(&array));
	point.x = 3;
	point.y = 5;
	D_ARRAY(push_back)(&array, &point);
	point.x = 5;
	point.y = 7;
	D_ARRAY(push_back)(&array, &point);
	uf_print_variadic("Add two new\n");
	uf_print_variadic("Capacity %d, Size %d\n", D_ARRAY(capacity)(&array), D_ARRAY(size)(&array));
	/*
	 * free memory used by array because we are nice !!
	 */
	D_ARRAY(destroy)(&array);
	(void)argc;
	(void)argv;
	return (0);
}
