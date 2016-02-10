/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2016/02/11 15:07:40 by sfroment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <setjmp.h>
#include <stdarg.h>
#include <cmocka.h>
#include <stdio.h>
#include <string.h>
#include <list/s_list.h>

static void
free_null(void *ptr)
{
	void	**ptr_bis = (void **)ptr;

	free(*ptr_bis);
	*ptr_bis = NULL;
}

static void
init(void **state) {
	// todo
	(void)state;
}

static void
empty_on_empty_list(void **state) {
	t_list	list;

	D_LIST(init)(&list, 0);
	assert_true(D_LIST(empty)(&list));
	D_LIST(destroy)(&list);
	(void)state;
}

static void
empty_on_non_empty_list(void **state) {
	t_list	list;

	D_LIST(init)(&list, 0);
	D_LIST(push_back)(&list, "Hello");
	D_LIST(push_back)(&list, "World");
	D_LIST(push_back)(&list, "!!!");

	assert_false(D_LIST(empty)(&list));

	D_LIST(destroy)(&list);
	(void)state;
}

static void
size(void **state) {
	t_list	list;

	D_LIST(init)(&list, 0);
	assert_int_equal(D_LIST(size)(&list), 0);
	D_LIST(push_back)(&list, "Hello");
	assert_int_equal(D_LIST(size)(&list), 1);
	D_LIST(push_back)(&list, "World");
	assert_int_equal(D_LIST(size)(&list), 2);
	D_LIST(push_back)(&list, "!!!");
	assert_int_equal(D_LIST(size)(&list), 3);

	D_LIST(destroy)(&list);
	(void)state;
}

static void
begin(void **state) {
	t_list	list;

	D_LIST(init)(&list, 0);
	D_LIST(push_back)(&list, "Hello");
	D_LIST(push_back)(&list, "World");
	D_LIST(push_back)(&list, "!!!");
	assert_string_equal(D_LIST(begin)(&list)->v_data, "Hello");
	D_LIST(pop_front)(&list);
	assert_string_equal(D_LIST(begin)(&list)->v_data, "World");
	D_LIST(pop_front)(&list);
	assert_string_equal(D_LIST(begin)(&list)->v_data, "!!!");
	D_LIST(pop_front)(&list);
	assert_null(D_LIST(begin)(&list));
	D_LIST(destroy)(&list);
	(void)state;
}

static void
end(void **state) {
	t_list	list;

	D_LIST(init)(&list, 0);
	D_LIST(push_back)(&list, "Hello");
	D_LIST(push_back)(&list, "World");
	D_LIST(push_back)(&list, "!!!");
	assert_string_equal(D_LIST(end)(&list)->v_data, "!!!");
	D_LIST(pop_back)(&list);
	assert_string_equal(D_LIST(end)(&list)->v_data, "World");
	D_LIST(pop_back)(&list);
	assert_string_equal(D_LIST(end)(&list)->v_data, "Hello");
	D_LIST(pop_back)(&list);
	assert_null(D_LIST(end)(&list));
	D_LIST(destroy)(&list);
	(void)state;
}

static void
erase(void **state) {
	char	data[] = "test";
	void	*data_test;
	t_list	list;

	D_LIST(init)(&list, 0);
	D_LIST(push_back)(&list, data);
	assert_null(D_LIST(erase)(&list, D_LIST(begin)(&list), &data_test));
	assert_string_equal(data, data_test);
	assert_ptr_equal(data, data_test);
	assert_true(D_LIST(empty)(&list));
	assert_int_equal(D_LIST(size)(&list), 0);
	D_LIST(destroy)(&list);
	(void)state;
}

static void
get_cell(void **state) {
	t_list	list;

	D_LIST(init)(&list, 0);
	D_LIST(push_back)(&list, "Hello");
	D_LIST(push_back)(&list, "World");
	D_LIST(push_back)(&list, "!!!");
	assert_ptr_equal(D_LIST(get_cell)(&list, 0), D_LIST(begin)(&list));
	assert_ptr_equal(D_LIST(get_cell)(&list, 2), D_LIST(end)(&list));
	D_LIST(destroy)(&list);
	(void)state;
}

static void
delete(void **state) {
	t_list	list;
	char	*data = strdup("Hello");

	D_LIST(init)(&list, free_null);
	D_LIST(push_back)(&list, &data);
	assert_null(D_LIST(delete)(&list, D_LIST(begin)(&list)));
	assert_null(data);
	D_LIST(destroy)(&list);
	(void)state;
}

static void
push_back(void **state) {
	int		i;
	t_list	list;

	i = 0;
	D_LIST(init)(&list, 0);
	while (i < 50)
	{
		assert_true(D_LIST(push_back)(&list, (void*)(size_t)i));
		++i;
	}
	D_LIST(destroy)(&list);
	(void)state;
}

static void
pop_back(void **state) {
	t_list	list;
	char	*data[3] =	{
							strdup("Hello"),
							strdup("World"),
							strdup("!!!"),
						};

	D_LIST(init)(&list, free_null);
	D_LIST(push_back)(&list, &data[0]);
	D_LIST(push_back)(&list, &data[1]);
	D_LIST(pop_back)(&list);
	assert_null(data[1]);
	D_LIST(push_back)(&list, &data[2]);
	D_LIST(pop_back)(&list);
	assert_null(data[2]);
	D_LIST(pop_back)(&list);
	assert_null(data[0]);
	D_LIST(destroy)(&list);
	(void)state;
}

static void
push_front(void **state) {
	int		i;
	t_list	list;

	i = 0;
	D_LIST(init)(&list, 0);
	while (i < 50)
	{
		assert_true(D_LIST(push_front)(&list, (void*)(size_t)i));
		++i;
	}
	D_LIST(destroy)(&list);
	(void)state;
}

static void
pop_front(void **state) {
	t_list	list;
	char	*data[3] =	{
							strdup("Hello"),
							strdup("World"),
							strdup("!!!"),
						};

	D_LIST(init)(&list, free_null);
	D_LIST(push_back)(&list, &data[0]);
	D_LIST(push_back)(&list, &data[1]);
	D_LIST(pop_front)(&list);
	assert_null(data[0]);
	D_LIST(push_back)(&list, &data[2]);
	D_LIST(pop_front)(&list);
	assert_null(data[1]);
	D_LIST(pop_front)(&list);
	assert_null(data[2]);
	D_LIST(destroy)(&list);
	(void)state;
}

static void
insert(void **state) {
	t_list		list;
	t_list_cell	*ptr;
	t_list_cell	*ptr_bis;

	D_LIST(init)(&list, 0);
	D_LIST(push_back)(&list, "Hello");
	ptr = D_LIST(begin)(&list);
	ptr_bis = D_LIST(insert)(&list, ptr, "World");
	assert_ptr_not_equal(ptr_bis, ptr);
	assert_ptr_equal(ptr_bis, D_LIST(begin)(&list));
	D_LIST(destroy)(&list);
	(void)state;
}

static void
back(void **state) {
	t_list	list;

	char	*data[3] =	{
							strdup("Hello"),
							strdup("World"),
							strdup("!!!"),
						};

	D_LIST(init)(&list, free);
	D_LIST(push_back)(&list, data[0]);
	D_LIST(push_back)(&list, data[2]);
	D_LIST(push_back)(&list, data[1]);
	assert_string_equal(D_LIST(back)(&list), data[1]);
	assert_ptr_equal(D_LIST(back)(&list), data[1]);
	D_LIST(destroy)(&list);
	(void)state;
}

static void
front(void **state) {
	t_list	list;

	char	*data[3] =	{
							strdup("Hello"),
							strdup("World"),
							strdup("!!!"),
						};

	D_LIST(init)(&list, free);
	D_LIST(push_back)(&list, data[0]);
	D_LIST(push_back)(&list, data[2]);
	D_LIST(push_back)(&list, data[1]);
	assert_string_equal(D_LIST(front)(&list), data[0]);
	assert_ptr_equal(D_LIST(front)(&list), data[0]);
	D_LIST(destroy)(&list);
	(void)state;
}

static void
split(void **state) {
	t_list		list;
	t_list		new_list;
	t_list_cell	*split_at;

	D_LIST(init)(&list, 0);
	D_LIST(init)(&new_list, 0);
	D_LIST(push_back)(&list, "Hello");
	D_LIST(push_back)(&list, "World");
	D_LIST(push_back)(&list, "!!!");
	split_at = D_LIST(get_cell)(&list, 1),
	D_LIST(split)(&list, split_at, &new_list);
	assert_ptr_equal(D_LIST(begin)(&new_list), split_at);
	assert_int_equal(D_LIST(size)(&list), 1);
	assert_int_equal(D_LIST(size)(&new_list), 2);
	D_LIST(destroy)(&list);
	D_LIST(destroy)(&new_list);
	(void)state;
}

static bool
s_foreach(void *value) {
	((char *)value)[0]++;
	return true;
}

static void
foreach(void **state) {
	t_list	list;
	int		i;
	char	c[50];

	i = 0;
	D_LIST(init)(&list, 0);
	while (i < 50)
	{
		c[i] = i;
		assert_true(D_LIST(push_back)(&list, &c[i]));
		++i;
	}
	D_LIST(foreach)(&list, s_foreach);
	i = 0;
	while (i < 50)
	{
		assert_int_equal(((char *)D_LIST(get_cell)(&list, i)->v_data)[0], i + 1);
		++i;
	}
	D_LIST(destroy)(&list);
	(void)state;
}

static void
reverse(void **state) {
	t_list		list;

	D_LIST(init)(&list, 0);
	D_LIST(push_back)(&list, "Hello");
	D_LIST(push_back)(&list, "World");
	D_LIST(push_back)(&list, "!!!");
	D_LIST(reverse)(&list);
	assert_string_equal(D_LIST(end)(&list)->v_data, "Hello");
	assert_string_equal(D_LIST(begin)(&list)->v_data, "!!!");
	assert_string_equal(D_LIST(get_cell)(&list, 1)->v_data, "World");
	D_LIST(destroy)(&list);
	(void)state;
}

static void
splice(void **state) {
	t_list                  list;
	t_list                  other_list;
	t_list_interval other_interval;

	D_LIST(init)(&list, 0);
	D_LIST(init)(&other_list, 0);
	D_LIST_INTERVAL(init)(&other_interval, D_LIST(begin)(&other_list), D_LIST(end)(&other_list));
	D_LIST(push_back)(&list, (void*)0); // list 0 1 2
	D_LIST(push_back)(&list, (void*)1);
	D_LIST(push_back)(&list, (void*)2);
	D_LIST(push_back)(&other_list, (void*)3); // other_list 3 4 5
	D_LIST(push_back)(&other_list, (void*)4);
	D_LIST(push_back)(&other_list, (void*)5);
	// position 1
	D_LIST(splice)(&list, D_LIST(begin)(&list)->v_next, &other_list, NULL);
	// so list 0 3 4 5 1 2
	assert_int_equal(D_LIST(size)(&list), 6);
	assert_int_equal(D_LIST(get_cell)(&list, 0)->v_data, 0);
	assert_int_equal(D_LIST(get_cell)(&list, 1)->v_data, 3);
	assert_int_equal(D_LIST(get_cell)(&list, 2)->v_data, 4);
	assert_int_equal(D_LIST(get_cell)(&list, 3)->v_data, 5);
	assert_int_equal(D_LIST(get_cell)(&list, 4)->v_data, 1);
	assert_int_equal(D_LIST(get_cell)(&list, 5)->v_data, 2);
	D_LIST(destroy)(&list);

	(void)state;
}


static bool
delete_if_0(void *data, void *value) {
	if (data == value)
		return (true);
	return (false);
}

static void
delete_if(void **state) {
	t_list	list;

	D_LIST(init)(&list, 0);
	D_LIST(push_back)(&list, (void*)0);
	D_LIST(push_back)(&list, (void*)1);
	D_LIST(push_back)(&list, (void*)3);
	D_LIST(delete_if)(&list, delete_if_0, (void*)0);
	assert_int_equal(D_LIST(front)(&list), 1);
	D_LIST(destroy)(&list);
	(void)state;
}

static void
clear(void **state) {
	t_list	list;

	D_LIST(init)(&list, 0);
	D_LIST(push_back)(&list, (void*)0);
	D_LIST(push_back)(&list, (void*)1);
	D_LIST(push_back)(&list, (void*)3);
	D_LIST(clear)(&list);
	assert_int_equal(D_LIST(size)(&list), 0);
	assert_true(D_LIST(empty)(&list));
	D_LIST(destroy)(&list);
	(void)state;
}

int		main(int argc, char const** argv)
{
	const struct CMUnitTest	test[] = {
		cmocka_unit_test(init),
		cmocka_unit_test(empty_on_empty_list),
		cmocka_unit_test(empty_on_non_empty_list),
		cmocka_unit_test(size),
		cmocka_unit_test(begin),
		cmocka_unit_test(end),
		cmocka_unit_test(erase),
		cmocka_unit_test(get_cell),
		cmocka_unit_test(delete),
		cmocka_unit_test(push_back),
		cmocka_unit_test(pop_back),
		cmocka_unit_test(push_front),
		cmocka_unit_test(pop_front),
		cmocka_unit_test(insert),
		cmocka_unit_test(back),
		cmocka_unit_test(front),
		cmocka_unit_test(split),
		cmocka_unit_test(foreach),
		cmocka_unit_test(reverse),
		cmocka_unit_test(splice),
		cmocka_unit_test(delete_if),
		cmocka_unit_test(clear),
	};

	(void)argc;
	(void)argv;
	return (cmocka_run_group_tests(test, NULL, NULL));
}
