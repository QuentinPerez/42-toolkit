/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vector.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/16 12:11:43 by qperez            #+#    #+#             */
/*   Updated: 2013/09/16 12:17:09 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_VECTOR_H
# define S_VECTOR_H

#include <t_types.h>
#include <d_bool.h>

typedef struct	s_vector
{
	
}				t_vector;

# define D_VECTOR(funct)	f_vector_##funct

bool	f_vector_init(t_vector *v_this);
void	f_vector_destroy(t_vector *v_this);

#endif
