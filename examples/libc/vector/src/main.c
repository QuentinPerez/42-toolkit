/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/05 15:08:40 by qperez            #+#    #+#             */
/*   Updated: 2013/09/16 12:53:54 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector/s_vector.h>
#include <stddef.h>

int	main(int argc, char const** argv)
{
	t_vector	vector;

	D_VECTOR(init)(&vector, NULL, NULL);
	D_VECTOR(destroy)(&vector);
	(void)argc;
	(void)argv;
	return (0);
}

