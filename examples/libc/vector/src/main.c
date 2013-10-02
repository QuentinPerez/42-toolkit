/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/05 15:08:40 by qperez            #+#    #+#             */
/*   Updated: 2013/10/02 13:34:18 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector/s_vector.h>
#include <stdlib.h>
#include <f_string/f_print.h>

static bool	uf_print(void *ptr)
{
	uf_print_str("Value : ");
	uf_print_nbr(*(int*)ptr);
	uf_print_char('\n');
	return (true);
}

int	main(int argc, char const** argv)
{
	ui			i;
	int			*ptr;
	t_vector	vector;

	i = 0;
	D_VECTOR(init)(&vector, NULL, NULL);
	while (i < 32)
	{
		ptr = malloc(sizeof(*ptr));
		*ptr = i;
		D_VECTOR(push_back)(&vector, ptr);
		i = i + 1;
	}
	D_VECTOR(foreach)(&vector, &uf_print);
	D_VECTOR(destroy)(&vector);
	(void)argc;
	(void)argv;
	return (0);
}

