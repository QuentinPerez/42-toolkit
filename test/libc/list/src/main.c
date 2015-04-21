/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2013/11/05 21:45:02 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <list/s_list.h>
#include <unit/s_unit.h>

bool	uf_cmp(void *d1, void *d2)
{
	return (*(int*)d1 == *(int*)d2);
}

void	D_UNIT_FUNCT(memleaks)
{
	int		i;
	int		*ptr;
	t_list	list;
	void	*data;

	i = 0;
	D_LIST(init)(&list, free);
	while (i < 5000)
	{
		ptr = malloc(sizeof(int));
		*ptr = i;
		D_LIST(push_back)(&list, ptr);
		i = i + 1;
	}
	D_LIST(erase)(&list, D_LIST(get_cell)(&list, 5), &data);
	free(data);
	*ptr = 10;
	D_LIST(delete_if)(&list, uf_cmp, ptr);
	D_LIST(delete)(&list, D_LIST(get_cell)(&list, 10));
	ptr = malloc(sizeof(int));
	*ptr = 16;
	D_LIST(insert)(&list, D_LIST(get_cell)(&list, 4), ptr);
	D_LIST(destroy)(&list);
	(void)t;
}

void	D_UNIT_FUNCT(getter)
{
	int		i;
	t_list	list;

	i = 0;
	D_LIST(init)(&list, 0);
	F_UNIT_ASSERT(D_LIST(empty)(&list) == true);
	F_UNIT_ASSERT(D_LIST(size)(&list) == 0);
	while (i < 50)
	{
		F_UNIT_ASSERT(D_LIST(push_back)(&list, (void*)(size_t)i) == 0);
		F_UNIT_ASSERT(D_LIST(push_front)(&list, (void*)(size_t)i) == 0);
		i = i + 1;
	}
	D_LIST(destroy)(&list);
}

int		main(int argc, char const** argv)
{
	t_unit	unit;

	D_UNIT(init)(&unit);
	D_UNIT(add_context)(&unit, "Leaks", 0, 0);
	F_UNIT_ADD_TEST(&unit, "Leaks", memleaks);
	D_UNIT(add_context)(&unit, "Method", 0, 0);
	F_UNIT_ADD_TEST(&unit, "Method", getter);
	D_UNIT(console_run)(&unit);
	D_UNIT(destroy)(&unit);
	(void)argc;
	(void)argv;
	return (0);
}
