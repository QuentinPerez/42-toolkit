/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sum_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmuller <clara.muller19@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/09 20:57:21 by cmuller           #+#    #+#             */
/*   Updated: 2013/11/09 21:48:55 by cmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_matrix.h"

struct s_matrix	*uf_sum_matrix(struct s_matrix *m1, struct s_matrix *m2)
{
	struct s_matrix	*res;
	int 		i;
	int 		j;

	if (m1->width != m2->width || m1->length != m2->length)
		return 0;
	res = uf_new_matrix(m1->width, m1->length);
	i = 0;
	while ( i < m1->length)
	{
		j = 0;
		while (j < m1->width)
		{
			res->coeff[i][j] = m1->coeff[i][j] + m2->coeff[i][j];
			j = j + 1;
		}
		i = i + 1;
	}
	return res;
}
