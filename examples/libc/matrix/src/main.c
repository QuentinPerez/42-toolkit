/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/13 12:58:04 by qperez            #+#    #+#             */
/*   Updated: 2013/11/12 18:13:50 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <matrix/s_matrix.h>

int		main(int argc, char const** argv)
{
	t_matrix	mat;

	/*
	 * Initialize the structure
	 */
	if (D_MATRIX(init)(&mat, 10, 10) == false)
	{
		return (-1);
	}
	D_MATRIX(print)(&mat, "identity");
	/*
	 * Destroy the structure
	 */
	D_MATRIX(destroy)(&mat);
	(void)argc;
	(void)argv;
	return (0);
}
