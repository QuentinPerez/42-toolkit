/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2013/11/05 13:21:29 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unit/s_unit.h>
#include <array/s_array.h>

struct	s_leaks
{
	int	*v_leak;
};

void	uf_delete_leak(void *d)
{
	struct s_leaks	*leak;

	leak = (struct s_leaks*)d;
	free(leak->v_leak);
}

bool	uf_cmp(void *d1, void *d2)
{
	return (*(int*)d1 == *(int*)d2);
}

void	D_UNIT_FUNCT(memleaks)
{
	int				i;
	t_array			array;
	struct s_leaks	leak;

	i = 0;
	D_ARRAY(init)(&array, 0, 0, sizeof(int));
	while (i < 987654)
	{
		D_ARRAY(push_back)(&array, &i);
		i = i + 1;
	}
	i = 67;
	D_ARRAY(delete_if)(&array, uf_cmp, &i);
	D_ARRAY(resize)(&array, 9876543);
	D_ARRAY(destroy)(&array);
	i = 0;
	D_ARRAY(init)(&array, 0, uf_delete_leak, sizeof(struct s_leaks));
	while (i < 987654)
	{
		leak.v_leak = malloc(sizeof(int));
		D_ARRAY(push_back)(&array, &leak);
		i = i + 1;
	}
	D_ARRAY(destroy)(&array);
	(void)t;
}

void	D_UNIT_FUNCT(getter)
{
	int		i;
	t_array	array;

	i = 0;
	D_ARRAY(init)(&array, 0, 0, sizeof(int));
	D_UNIT(assert)(D_ARRAY(data)(&array, int) != 0);
	D_UNIT(assert)(D_ARRAY(at)(&array, 0, int) != 0);
	D_UNIT(assert)(D_ARRAY(size)(&array) == 0);
	D_UNIT(assert)(D_ARRAY(empty)(&array) == 1);
	while (i < 987654)
	{
		D_ARRAY(push_back)(&array, &i);
		i = i + 1;
	}
	D_UNIT(assert)(D_ARRAY(size)(&array) == 987654);
	D_UNIT(assert)(D_ARRAY(empty)(&array) == 0);
	D_ARRAY(destroy)(&array);
}

bool	uf_foreach(void *d)
{
	(void)d;
	return (true);
}

void	D_UNIT_FUNCT(ret_val)
{
	int		i;
	t_array	array;

	i = 0;
	D_UNIT(assert)(D_ARRAY(init)(&array, 0, 0, sizeof(int)) == 1);
	while (i < 987654)
	{
		D_UNIT(assert)(D_ARRAY(push_back)(&array, &i) == 1);
		i = i + 1;
	}
	D_UNIT(assert)(D_ARRAY(foreach)(&array, uf_foreach) == 1);
	D_ARRAY(destroy)(&array);
}

int		main(int argc, char const** argv)
{
	t_unit	unit;

	D_UNIT(init)(&unit);
	D_UNIT(add_context)(&unit, "Leaks", 0, 0);
	D_UNIT(add_context)(&unit, "Method", 0, 0);
	D_UNIT(add_test)(&unit, "Leaks", memleaks);
	D_UNIT(add_test)(&unit, "Method", getter);
	D_UNIT(add_test)(&unit, "Method", ret_val);
	D_UNIT(console_run)(&unit);
	D_UNIT(destroy)(&unit);
	(void)argc;
	(void)argv;
	return (0);
}
