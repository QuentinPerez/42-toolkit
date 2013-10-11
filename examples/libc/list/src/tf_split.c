/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_split.c                                         :+:      :+:    :+:   */
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
void	uf_add_number_to_list(t_list *list, size_t number);

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
