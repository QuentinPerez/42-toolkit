/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/13 12:58:04 by qperez            #+#    #+#             */
/*   Updated: 2014/10/05 13:10:21 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <matrix/s_imatrix.h>

int		main(int argc, char const** argv)
{
	t_imatrix	mat;

	/*
	 * Initialize the structure
	 */
	if (D_IMATRIX(init)(&mat, 10, 10) == false)
	{
		return (-1);
	}
	D_IMATRIX(print)(&mat, "identity");
	/*
	 * Destroy the structure
	 */
	D_IMATRIX(destroy)(&mat);
	(void)argc;
	(void)argv;
	return (0);
}
