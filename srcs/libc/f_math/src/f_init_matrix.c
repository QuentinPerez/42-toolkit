/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmuller <clara.muller19@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/09 20:24:48 by cmuller           #+#    #+#             */
/*   Updated: 2013/11/09 21:47:22 by cmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_matrix.h"

void uf_init_matrix(struct s_matrix *m)
{
	int i;
	int j;

	i = 0;
	while (i < m->length)
	{
		j = 0;
		while ( j < m->width)
		{
			m->coeff[i][j] = 0;
			j = j + 1;
		}
		i = i + 1;
	}
}
