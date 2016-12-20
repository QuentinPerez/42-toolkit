/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_matrix.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmuller <clara.muller19@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/09 19:20:01 by cmuller           #+#    #+#             */
/*   Updated: 2013/11/09 21:50:29 by cmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_MATRIX_H
# define F_MATRIX_H

typedef struct	s_matrix
{
	float	**coeff;
	int	width;
	int	length;
}		t_matrix;


struct s_matrix	*uf_new_matrix(int w, int l);

void		uf_init_matrix(struct s_matrix *mat);

struct s_matrix	*uf_sum_matrix(struct s_matrix m1, struct s_matrix m2);


#endif
