/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/22 12:13:53 by qperez            #+#    #+#             */
/*   Updated: 2013/10/22 12:29:53 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STRING_H
# define S_STRING_H

#include <d_bool.h>
#include <t_types.h>

typedef struct	s_string
{
	char		*v_str;
	ui			v_size;
	ui			v_capacity;
	const char	*v_hex;
	ui			(*f_realloc)(ui size);
}				t_string;

# define D_STRING(funct)	f_string_##funct

bool	f_string_init(t_string *v_this, ui (*uf_realloc)(ui size));
void	f_string_destroy(t_string *v_this);

#endif
