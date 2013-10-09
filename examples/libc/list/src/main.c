/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/05 15:08:40 by qperez            #+#    #+#             */
/*   Updated: 2013/10/07 11:59:26 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list/s_list.h>
#include <f_string/f_print.h>
#include <stddef.h>

bool	uf_print_value(void *data)
{
	uf_print_str("Value : ");
	uf_print_nbr((size_t)data);
	uf_print_char('\n');
	return (true);
}

void	uf_check_equal_ui(ui expected, ui current)
{
	if (expected == current)
	{
		uf_print_str("OK: ");
		uf_print_nbr(expected);
		uf_print_str(" == ");
		uf_print_nbr(current);
		uf_print_char('\n');
	}
	else
	{
		uf_print_str("FAIL: ");
		uf_print_nbr(expected);
		uf_print_str(" != ");
		uf_print_nbr(current);
		uf_print_char('\n');
	}
}

void	tf_cell_count(void)
{
	t_list	list;
	int		i;
	
	i = 0;
	uf_print_str("Test cell_count\n");
	D_LIST(init)(&list, NULL);
	uf_check_equal_ui(D_LIST(size)(&list),
					  D_CELL(count)(list.v_begin, list.v_end));
	while (i < 5)
	{
		D_LIST(push_back)(&list, (void *)i);
		i = i + 1;
	}
	uf_check_equal_ui(D_LIST(size)(&list),
					  D_CELL(count)(list.v_begin, list.v_end));
}

void	tf_list_split01(void)
{
	t_list	listA;
	t_list	listB;
	
	uf_print_str("Test list_splice 01\n");
	D_LIST(init)(&listA, NULL);
	D_LIST(init)(&listB, NULL);
	D_LIST(push_back)(&listA, (void *)0);
	D_LIST(push_back)(&listA, (void *)1);
	D_LIST(push_back)(&listA, (void *)2);
	D_LIST(push_back)(&listA, (void *)3);
	D_LIST(split)(&listA, D_LIST(begin)(&listA), &listB);
	uf_check_equal_ui(D_LIST(size)(&listA), 0);
	uf_check_equal_ui(D_LIST(size)(&listB), 4);
	uf_check_equal_ui((ui)D_LIST(get_cell)(&listB, 0)->v_data, 0);
	uf_check_equal_ui((ui)D_LIST(get_cell)(&listB, 1)->v_data, 1);
	uf_check_equal_ui((ui)D_LIST(get_cell)(&listB, 2)->v_data, 2);
	uf_check_equal_ui((ui)D_LIST(get_cell)(&listB, 3)->v_data, 3);
	D_LIST(destroy)(&listA);
	D_LIST(destroy)(&listB);
}

void	tf_list_split02(void)
{
	t_list	listA;
	t_list	listB;
	
	uf_print_str("Test list_splice 02\n");
	D_LIST(init)(&listA, NULL);
	D_LIST(init)(&listB, NULL);
	D_LIST(push_back)(&listA, (void *)0);
	D_LIST(push_back)(&listA, (void *)1);
	D_LIST(push_back)(&listA, (void *)2);
	D_LIST(push_back)(&listA, (void *)3);
	D_LIST(split)(&listA, D_LIST(begin)(&listA)->v_next, &listB);
	uf_check_equal_ui(D_LIST(size)(&listA), 1);
	uf_check_equal_ui(D_LIST(size)(&listB), 3);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 0)->v_data), 0);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listB, 0)->v_data), 1);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listB, 1)->v_data), 2);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listB, 2)->v_data), 3);
	D_LIST(destroy)(&listA);
	D_LIST(destroy)(&listB);
}

void	tf_list_split03()
{
	t_list	listA;
	t_list	listB;
	
	uf_print_str("Test list_splice 03\n");
	D_LIST(init)(&listA, NULL);
	D_LIST(init)(&listB, NULL);
	D_LIST(push_back)(&listA, (void *)0);
	D_LIST(push_back)(&listA, (void *)1);
	D_LIST(push_back)(&listA, (void *)2);
	D_LIST(push_back)(&listA, (void *)3);
	D_LIST(split)(&listA, D_LIST(get_cell)(&listA, 3), &listB);
	uf_check_equal_ui(D_LIST(size)(&listA), 3);
	uf_check_equal_ui(D_LIST(size)(&listB), 1);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 0)->v_data), 0);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 1)->v_data), 1);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 2)->v_data), 2);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listB, 0)->v_data), 3);
	D_LIST(destroy)(&listA);
	D_LIST(destroy)(&listB);
}

int	main(int argc, char const** argv)
{
	t_list	list;
	size_t	i;

	i = 0;
	D_LIST(init)(&list, NULL);
	while (i < 5)
	{
		uf_print_str("Push back : ");
		uf_print_nbr(i);
		uf_print_char('\n');
		D_LIST(push_back)(&list, (void *)i);
		i = i + 1;
	}
	D_LIST(insert)(&list, D_LIST(end)(&list)->v_next, (void*)-1);
	D_LIST(print_addr)(&list);
	D_LIST(foreach)(&list, uf_print_value);
	D_LIST(destroy)(&list);
	tf_cell_count();
	tf_list_split01();
	tf_list_split02();
	tf_list_split03();
	(void)argc;
	(void)argv;
	return (0);
}
