/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/16 12:55:00 by qperez            #+#    #+#             */
/*   Updated: 2014/03/19 15:11:39 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <timer/s_timer.h>
#include <f_sort/f_sort.h>
#include <f_string/f_print.h>
#include <f_error/m_error.h>
#include <stdlib.h>
#include <time.h>

#define	SIZE_TAB	30000

static void uf_init(int *tab)
{
	t_ui	i;

	i = 0;
	srand(time(NULL));
	while (i < SIZE_TAB)
	{
		tab[i] = rand() % SIZE_TAB;
		i = i + 1;
	}
}

static bool	uf_check_if_tab_is_sorted(int *tab)
{
	t_ui	i;

	i = 0;
	while (i < SIZE_TAB - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			return (false);
		}
		i = i + 1;
	}
	return (true);
}

void	uf_print_tab(int *tab)
{
	t_ui	i;

	i = 0;
	while (i < SIZE_TAB)
	{
		uf_print_nbr(tab[i]);
		uf_print_char(' ');
		i = i + 1;
	}
}

void	tf_launch(const char *name, void (*sort)(int *, t_ui))
{
	t_timer	timer;
	int		ptr_int[SIZE_TAB];

	M_INFOS(name);
	uf_init(ptr_int);
	D_TIMER(start)(&timer);
	sort(ptr_int, SIZE_TAB);
	D_TIMER(pause)(&timer);
	if (uf_check_if_tab_is_sorted(ptr_int) == true)
	{
		uf_print_nbr(D_TIMER(get_ticks)(&timer));
		uf_print_str(" milliseconds\n\n");
	}
	else
		uf_print_tab(ptr_int);
}

/*
 * This file is a little example of the t_array structure
 */

int	main(int argc, char const** argv)
{
	/*
 	* Who has the biggest ...
	 */
	tf_launch("Shell", uf_sort_shell);
	tf_launch("Counting", (void (*)(int*, t_ui))uf_sort_counting);
	tf_launch("Quick", uf_sort_quick);
	tf_launch("Merge", (void (*)(int*, t_ui))uf_sort_merge);
	tf_launch("Bubble", uf_sort_bubble);
	(void)argc;
	(void)argv;
	return (0);
}

