/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 16:40:56 by qperez            #+#    #+#             */
/*   Updated: 2015/04/22 22:04:57 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <f_error/m_error.h>
#include <stdio.h>

/*
 * This file is a little example errors macros
 */

int		main(int argc, const char **argv)
{
	char	*foo;
	void	*bar;

	/*
	 * Beware this is the best tools !!
	 * He say with it's his code !!
	 * ...
	 * BANGGG !!
	 */
	/*
	 * This function return the first parameter, show error and it's amazing
	 * We begin with an easy
	 */
	M_ERROR(false, "It's nice but not amazing");
	/*
	 * Ok Level Up
	 */
	M_ERROR(42, "Nice it's an integer YOUHOU");
	/*
	 * Next Level
	 */
	bar = (void *)0xdeadb0ff;
	M_ERROR((size_t)bar, "What you want that i return an adress ? Easy it's %p", bar);
	/*
	 * WHOOHA Ok it's amazing and you can pass arguments !!
	 */
	/*
	 * Next Level
	 * No it's not possible what again
	 */
	foo = (char *)M_ERROR((size_t)argv[0], "Easy bro %s", argv[0]);
	(void)foo;
	(void)argv;
	(void)argc;
	return (0);
}
