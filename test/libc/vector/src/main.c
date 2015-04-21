/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2013/11/05 22:05:41 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <vector/s_vector.h>
#include <unit/s_unit.h>

void	D_UNIT_FUNCT(memleaks)
{
	int			i;
	t_vector	vector;

	i = 0;
	D_VECTOR(init)(&vector, 0, 0);
	while (i < 5000)
	{
		D_VECTOR(push_back)(&vector, (void*)(size_t)i);
		i = i + 1;
	}
	D_VECTOR(destroy)(&vector);
	(void)t;
}

int		main(int argc, char const** argv)
{
	t_unit	unit;

	D_UNIT(init)(&unit);
	D_UNIT(add_context)(&unit, "Leaks", 0, 0);
	F_UNIT_ADD_TEST(&unit, "Leaks", memleaks);
	D_UNIT(console_run)(&unit);
	D_UNIT(destroy)(&unit);
	(void)argc;
	(void)argv;
	return (0);
}
