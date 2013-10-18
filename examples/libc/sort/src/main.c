/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/16 12:55:00 by qperez            #+#    #+#             */
/*   Updated: 2013/10/18 12:58:05 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <timer/s_timer.h>
#include <sort/s_sort.h>
#include <f_string/f_print.h>
#include <stdlib.h>

#define	SIZE_TAB	500

static void uf_init(int *tab)
{
	ui	i;

	i = 0;
	while (i < SIZE_TAB)
	{
		tab[i] = rand() % SIZE_TAB;
		i = i + 1;
	}
}

static void	uf_print(int *tab)
{
	ui	i;

	i = 0;
	uf_print_str("[ ");
	while (i < SIZE_TAB)
	{
		uf_print_nbr(tab[i]);
		uf_print_char(' ');
		i = i + 1;
	}
	uf_print_str("]\n");
}

static bool	uf_cmp(void *left, void *right)
{
	return (*((int*)left) > *((int*)right));
}

static void	uf_swap(void *left, void *right)
{
	int	tmp;

	tmp = *(int*)left;
	*(int*)left = *(int*)right;
	*((int*)right) = tmp;
}

int	main(int argc, char const** argv)
{
	t_sort	sort;
	t_timer	timer;
	int		ptr_int[SIZE_TAB];

	uf_init(ptr_int);
	uf_print(ptr_int);
	D_SORT(init)(&sort, uf_cmp, uf_swap, sizeof(ptr_int) / SIZE_TAB);
	D_TIMER(start)(&timer);
	D_SORT(bubble)(&sort, ptr_int, SIZE_TAB);
	D_TIMER(pause)(&timer);
	uf_print_str("sort in ");
	uf_print_nbr(D_TIMER(get_ticks)(&timer));
	uf_print_str(" milliseconds\n");
	uf_print(ptr_int);
	(void)argc;
	(void)argv;
	return (0);
}

