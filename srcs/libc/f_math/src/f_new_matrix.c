/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_new_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmuller <clara.muller19@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/09 19:25:29 by cmuller           #+#    #+#             */
/*   Updated: 2013/11/09 21:45:24 by cmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_matrix.h"
#include <stdlib.h>

struct s_matrix	*uf_new_matrix(int w, int l)
{
	int i;
	struct s_matrix *res;

	i = 0;
	res = malloc (sizeof(*res));
	if (res == 0)
		return 0;
	res->coeff = malloc(sizeof(float) * l);
	if (res->coeff == 0)
		return 0;
	while ( i < l)
	{
		res->coeff[i] = malloc(sizeof(float) * w);
		if (res->coeff[i] == 0)
			return 0;
		i = i + 1;
	}
	res->width = w;
	res->length = l;
	return res;
}
