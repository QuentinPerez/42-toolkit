/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/05 15:08:40 by qperez            #+#    #+#             */
/*   Updated: 2013/09/16 15:30:30 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector/s_vector.h>
#include <stddef.h>
#include <stdlib.h>
#include <f_string/f_print.h>

static void	uf_print(void *ptr)
{
	uf_print_str("Destroy ptr : ");
	uf_print_nbr(*(int*)ptr);
	uf_print_char('\n');
}

int	main(int argc, char const** argv)
{
	uint		i;
	int			*ptr;
	t_vector	vector;

	i = 0;
	D_VECTOR(init)(&vector, NULL, &uf_print);
	while (i < 256)
	{
		ptr = malloc(sizeof(*ptr));
		*ptr = i;
		D_VECTOR(push_back)(&vector, ptr);
		i = i + 1;
	}
	D_VECTOR(destroy)(&vector);
	(void)argc;
	(void)argv;
	return (0);
}

