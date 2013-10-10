/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_splice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/05 04:53:10 by irabeson          #+#    #+#             */
/*   Updated: 2013/09/05 04:55:10 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list/s_list.h>
#include <f_string/f_print.h>
#include <f_error/m_error.h>
#include <stddef.h>

void	uf_check_equal_ui(ui expected, ui current);

void	tf_list_splice01(void)
{
	t_list			listA;
	t_list			listB;
	t_list_interval	interval;
	
	m_infos("Test list splice 01");
	D_LIST(init)(&listA, NULL);
	D_LIST(init)(&listB, NULL);
	D_LIST(push_back)(&listA, (void *)0);
	D_LIST(push_back)(&listA, (void *)3);
	D_LIST(push_back)(&listB, (void *)-1);
	D_LIST(push_back)(&listB, (void *)1);
	D_LIST(push_back)(&listB, (void *)2);
	D_LIST(push_back)(&listB, (void *)-2);
	D_LIST_INTERVAL(init)(&interval, D_LIST(begin)(&listB)->v_next,
						  D_LIST(end)(&listB)->v_prev);
	D_LIST(splice)(&listA, D_LIST(begin)(&listA)->v_next, &listB, &interval);
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
	t_list			listA;
	t_list			listB;
	t_list_interval	interval;

	m_infos("Test list splice 02");
	D_LIST(init)(&listA, NULL);
	D_LIST(init)(&listB, NULL);
	D_LIST(push_back)(&listA, (void *)2);
	D_LIST(push_back)(&listA, (void *)3);
	D_LIST(push_back)(&listB, (void *)-1);
	D_LIST(push_back)(&listB, (void *)0);
	D_LIST(push_back)(&listB, (void *)1);
	D_LIST(push_back)(&listB, (void *)-2);
	D_LIST_INTERVAL(init)(&interval, D_LIST(begin)(&listB)->v_next,
						  D_LIST(end)(&listB)->v_prev);
	D_LIST(splice)(&listA, D_LIST(begin)(&listA), &listB, &interval);
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
	t_list			listA;
	t_list			listB;
	t_list_interval	interval;

	m_infos("Test list splice 03");
	D_LIST(init)(&listA, NULL);
	D_LIST(init)(&listB, NULL);
	D_LIST(push_back)(&listA, (void *)0);
	D_LIST(push_back)(&listA, (void *)1);
	D_LIST(push_back)(&listB, (void *)-1);
	D_LIST(push_back)(&listB, (void *)2);
	D_LIST(push_back)(&listB, (void *)3);
	D_LIST(push_back)(&listB, (void *)-2);
	D_LIST_INTERVAL(init)(&interval, D_LIST(begin)(&listB)->v_next,
						  D_LIST(end)(&listB)->v_prev);
	D_LIST(splice)(&listA, NULL, &listB, &interval);
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
	t_list			listA;
	t_list			listB;
	t_list_interval	interval;

	m_infos("Test list splice 04");
	D_LIST(init)(&listA, NULL);
	D_LIST(init)(&listB, NULL);
	D_LIST(push_back)(&listB, (void *)-1);
	D_LIST(push_back)(&listB, (void *)0);
	D_LIST(push_back)(&listB, (void *)1);
	D_LIST(push_back)(&listB, (void *)2);
	D_LIST(push_back)(&listB, (void *)3);
	D_LIST(push_back)(&listB, (void *)-2);
	D_LIST_INTERVAL(init)(&interval, D_LIST(begin)(&listB)->v_next,
						  D_LIST(end)(&listB)->v_prev);
	D_LIST(splice)(&listA, NULL, &listB, &interval);
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
	t_list			listA;
	t_list			listB;
	t_list_interval	interval;

	m_infos("Test list splice 05");
	D_LIST(init)(&listA, NULL);
	D_LIST(init)(&listB, NULL);
	D_LIST(push_back)(&listB, (void *)0);
	D_LIST(push_back)(&listB, (void *)1);
	D_LIST(push_back)(&listB, (void *)2);
	D_LIST(push_back)(&listB, (void *)3);
	D_LIST_INTERVAL(init)(&interval, D_LIST(begin)(&listB),
						  D_LIST(end)(&listB));
	D_LIST(splice)(&listA, NULL, &listB, &interval);
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
	t_list			listA;
	t_list			listB;
	t_list_interval	interval;

	m_infos("Test list splice 06");
	D_LIST(init)(&listA, NULL);
	D_LIST_INTERVAL(init)(&interval, D_LIST(begin)(&listB),
						  D_LIST(end)(&listB));
	D_LIST(begin)(&listB), D_LIST(end)(&listB);
	D_LIST(splice)(&listA, NULL, &listB, &interval);
	uf_check_equal_ui((ui)(D_LIST(size)(&listA)), 0);
	uf_check_equal_ui((ui)(D_LIST(size)(&listB)), 0);
	D_LIST(destroy)(&listA);
	D_LIST(destroy)(&listB);
}

void	tf_list_splice07(void)
{
	t_list			listA;
	t_list			listB;
	t_list_interval	interval;

	m_infos("Test list splice 07");
	D_LIST(init)(&listA, NULL);
	D_LIST(init)(&listB, NULL);
	
	D_LIST(push_back)(&listA, (void *)0);
	D_LIST(push_back)(&listA, (void *)2);
	D_LIST(push_back)(&listB, (void *)1);
	D_LIST(push_back)(&listB, (void *)3);
	D_LIST(push_back)(&listB, (void *)5);
	D_LIST_INTERVAL(init)(&interval, D_LIST(begin)(&listB),
						  D_LIST(begin)(&listB));
	D_LIST(splice)(&listA, D_LIST(begin)(&listA)->v_next, &listB, &interval);
	D_LIST_INTERVAL(init)(&interval, D_LIST(begin)(&listB),
						  D_LIST(begin)(&listB));
	D_LIST(splice)(&listA, NULL, &listB, &interval);
	uf_check_equal_ui((ui)(D_LIST(size)(&listA)), 4);
	uf_check_equal_ui((ui)(D_LIST(size)(&listB)), 1);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 0)->v_data), 0);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 1)->v_data), 1);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 2)->v_data), 2);
	uf_check_equal_ui((ui)(D_LIST(get_cell)(&listA, 3)->v_data), 3);
	D_LIST(destroy)(&listA);
	D_LIST(destroy)(&listB);
}
