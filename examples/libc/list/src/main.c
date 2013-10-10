/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/05 15:08:40 by qperez            #+#    #+#             */
/*   Updated: 2013/10/09 23:44:21 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list/s_list.h>
#include <f_string/f_print.h>
#include <stddef.h>
#include <f_error/m_error.h>

void	uf_check_equal_ui(ui expected, ui current);
void	tf_cell_count(void);
void	tf_list_split01(void);
void	tf_list_split02(void);
void	tf_list_split03(void);
void	tf_list_splice01(void);
void	tf_list_splice02(void);
void	tf_list_splice03(void);
void	tf_list_splice04(void);
void	tf_list_splice05(void);
void	tf_list_splice06(void);
void	tf_list_splice07(void);

int		main(int argc, char const** argv)
{
	tf_cell_count();
	tf_list_split01();
	tf_list_split02();
	tf_list_split03();
	tf_list_splice01();
	tf_list_splice02();
	tf_list_splice03();
	tf_list_splice04();
	tf_list_splice05();
	tf_list_splice06();
	tf_list_splice07();
	(void)argc;
	(void)argv;
	return (0);
}

void	uf_check_equal_ui(ui expected, ui current)
{
	if (expected == current)
		uf_print_str("\e[32mOK\e[0m\n");
	else
	{
		uf_print_str("\e[31mFAIL\e[0m: ");
		uf_print_nbr(expected);
		uf_print_str(" != ");
		uf_print_nbr(current);
		uf_print_char('\n');
	}
}

void	tf_cell_count(void)
{
	t_list	list;
	size_t	i;

	i = 0;
	m_infos("Test cell count");
	D_LIST(init)(&list, NULL);
	uf_check_equal_ui(D_LIST(size)(&list),
					  D_LIST_CELL(count)(list.v_begin, list.v_end));
	while (i < 5)
	{
		D_LIST(push_back)(&list, (void *)i);
		i = i + 1;
	}
	uf_check_equal_ui(D_LIST(size)(&list),
					  D_LIST_CELL(count)(list.v_begin, list.v_end));
	uf_check_equal_ui(4,
					  D_LIST_CELL(count)(list.v_begin, list.v_end->v_prev));
	uf_check_equal_ui(4,
					  D_LIST_CELL(count)(list.v_begin->v_next, list.v_end));
	uf_check_equal_ui(1,
					  D_LIST_CELL(count)(list.v_begin->v_next,
										 list.v_begin->v_next));
	D_LIST(destroy)(&list);
}

void	uf_add_number_to_list(t_list *list, size_t number)
{
	size_t	i;

	i = 0;
	while (i < number)
	{
		D_LIST(push_back)(list, (void *)i);
		i = i + 1;
	}
}

void	tf_list_split01(void)
{
	t_list	listA;
	t_list	listB;

	m_infos("Test list split 01");
	D_LIST(init)(&listA, NULL);
	D_LIST(init)(&listB, NULL);
	uf_add_number_to_list(&listA, 4);
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

	m_infos("Test list split 02");
	D_LIST(init)(&listA, NULL);
	D_LIST(init)(&listB, NULL);
	uf_add_number_to_list(&listA, 4);
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

void	tf_list_split03(void)
{
	t_list	listA;
	t_list	listB;

	m_infos("Test list split 03");
	D_LIST(init)(&listA, NULL);
	D_LIST(init)(&listB, NULL);
	uf_add_number_to_list(&listA, 4);
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

bool	uf_print_ui(void *data)
{
	uf_print_nbr((ui)data);
	return (true);
}

void	tf_list_splice01(void)
{
	t_list	listA;
	t_list	listB;
	
	m_infos("Test list splice 01");
	D_LIST(init)(&listA, NULL);
	D_LIST(init)(&listB, NULL);
	D_LIST(push_back)(&listA, (void *)0);
	D_LIST(push_back)(&listA, (void *)3);
	D_LIST(push_back)(&listB, (void *)-1);
	D_LIST(push_back)(&listB, (void *)1);
	D_LIST(push_back)(&listB, (void *)2);
	D_LIST(push_back)(&listB, (void *)-2);
	f_list_splice(&listA, D_LIST(begin)(&listA)->v_next, &listB,
				  D_LIST(begin)(&listB)->v_next, D_LIST(end)(&listB)->v_prev);
	uf_check_equal_ui((ui)(D_LIST(size)(&listA)), 4);
	uf_check_equal_ui((ui)(D_LIST(size)(&listB)), 2);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 0)->v_data), 0);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 1)->v_data), 1);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 2)->v_data), 2);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 3)->v_data), 3);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listB, 0)->v_data), -1);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listB, 1)->v_data), -2);
	D_LIST(destroy)(&listA);
	D_LIST(destroy)(&listB);
}

void	tf_list_splice02(void)
{
	t_list	listA;
	t_list	listB;
	
	m_infos("Test list splice 02");
	D_LIST(init)(&listA, NULL);
	D_LIST(init)(&listB, NULL);
	D_LIST(push_back)(&listA, (void *)2);
	D_LIST(push_back)(&listA, (void *)3);
	D_LIST(push_back)(&listB, (void *)-1);
	D_LIST(push_back)(&listB, (void *)0);
	D_LIST(push_back)(&listB, (void *)1);
	D_LIST(push_back)(&listB, (void *)-2);
	f_list_splice(&listA, D_LIST(begin)(&listA), &listB,
				  D_LIST(begin)(&listB)->v_next, D_LIST(end)(&listB)->v_prev);
	uf_check_equal_ui((ui)(D_LIST(size)(&listA)), 4);
	uf_check_equal_ui((ui)(D_LIST(size)(&listB)), 2);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 0)->v_data), 0);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 1)->v_data), 1);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 2)->v_data), 2);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 3)->v_data), 3);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listB, 0)->v_data), -1);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listB, 1)->v_data), -2);
	D_LIST(destroy)(&listA);
	D_LIST(destroy)(&listB);
}

void	tf_list_splice03(void)
{
	t_list	listA;
	t_list	listB;
	
	m_infos("Test list splice 03");
	D_LIST(init)(&listA, NULL);
	D_LIST(init)(&listB, NULL);
	D_LIST(push_back)(&listA, (void *)0);
	D_LIST(push_back)(&listA, (void *)1);
	D_LIST(push_back)(&listB, (void *)-1);
	D_LIST(push_back)(&listB, (void *)2);
	D_LIST(push_back)(&listB, (void *)3);
	D_LIST(push_back)(&listB, (void *)-2);
	f_list_splice(&listA, NULL, &listB,
				  D_LIST(begin)(&listB)->v_next, D_LIST(end)(&listB)->v_prev);
	uf_check_equal_ui((ui)(D_LIST(size)(&listA)), 4);
	uf_check_equal_ui((ui)(D_LIST(size)(&listB)), 2);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 0)->v_data), 0);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 1)->v_data), 1);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 2)->v_data), 2);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 3)->v_data), 3);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listB, 0)->v_data), -1);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listB, 1)->v_data), -2);
	D_LIST(destroy)(&listA);
	D_LIST(destroy)(&listB);
}

void	tf_list_splice04(void)
{
	t_list	listA;
	t_list	listB;
	
	m_infos("Test list splice 04");
	D_LIST(init)(&listA, NULL);
	D_LIST(init)(&listB, NULL);
	D_LIST(push_back)(&listB, (void *)-1);
	D_LIST(push_back)(&listB, (void *)0);
	D_LIST(push_back)(&listB, (void *)1);
	D_LIST(push_back)(&listB, (void *)2);
	D_LIST(push_back)(&listB, (void *)3);
	D_LIST(push_back)(&listB, (void *)-2);
	f_list_splice(&listA, NULL, &listB,
				  D_LIST(begin)(&listB)->v_next, D_LIST(end)(&listB)->v_prev);
	uf_check_equal_ui((ui)(D_LIST(size)(&listA)), 4);
	uf_check_equal_ui((ui)(D_LIST(size)(&listB)), 2);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 0)->v_data), 0);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 1)->v_data), 1);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 2)->v_data), 2);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 3)->v_data), 3);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listB, 0)->v_data), -1);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listB, 1)->v_data), -2);
	D_LIST(destroy)(&listA);
	D_LIST(destroy)(&listB);
}

void	tf_list_splice05(void)
{
	t_list	listA;
	t_list	listB;
	
	m_infos("Test list splice 05");
	D_LIST(init)(&listA, NULL);
	D_LIST(init)(&listB, NULL);
	D_LIST(push_back)(&listB, (void *)0);
	D_LIST(push_back)(&listB, (void *)1);
	D_LIST(push_back)(&listB, (void *)2);
	D_LIST(push_back)(&listB, (void *)3);
	f_list_splice(&listA, NULL, &listB,
				  D_LIST(begin)(&listB), D_LIST(end)(&listB));
	uf_check_equal_ui((ui)(D_LIST(size)(&listA)), 4);
	uf_check_equal_ui((ui)(D_LIST(size)(&listB)), 0);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 0)->v_data), 0);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 1)->v_data), 1);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 2)->v_data), 2);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 3)->v_data), 3);
	D_LIST(destroy)(&listA);
	D_LIST(destroy)(&listB);
}

void	tf_list_splice06(void)
{
	t_list	listA;
	t_list	listB;
	
	m_infos("Test list splice 06");
	D_LIST(init)(&listA, NULL);
	D_LIST(init)(&listB, NULL);
	f_list_splice(&listA, NULL, &listB,
				  D_LIST(begin)(&listB), D_LIST(end)(&listB));
	uf_check_equal_ui((ui)(D_LIST(size)(&listA)), 0);
	uf_check_equal_ui((ui)(D_LIST(size)(&listB)), 0);
	D_LIST(destroy)(&listA);
	D_LIST(destroy)(&listB);
}

void	tf_list_splice07(void)
{
	t_list	listA;
	t_list	listB;
	
	m_infos("Test list splice 07");
	D_LIST(init)(&listA, NULL);
	D_LIST(init)(&listB, NULL);
	
	D_LIST(push_back)(&listA, (void *)0);
	D_LIST(push_back)(&listA, (void *)2);
	D_LIST(push_back)(&listB, (void *)1);
	D_LIST(push_back)(&listB, (void *)3);
	D_LIST(push_back)(&listB, (void *)5);
	f_list_splice(&listA, D_LIST(begin)(&listA)->v_next, &listB,
				  D_LIST(begin)(&listB), D_LIST(begin)(&listB));
	f_list_splice(&listA, NULL, &listB,
				  D_LIST(begin)(&listB), D_LIST(begin)(&listB));
	uf_check_equal_ui((ui)(D_LIST(size)(&listA)), 4);
	uf_check_equal_ui((ui)(D_LIST(size)(&listB)), 1);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 0)->v_data), 0);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 1)->v_data), 1);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 2)->v_data), 2);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 3)->v_data), 3);
	D_LIST(destroy)(&listA);
	D_LIST(destroy)(&listB);
}
