/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_htable_private.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/09 08:25:06 by qperez            #+#    #+#             */
/*   Updated: 2013/10/09 08:35:32 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <htable/s_htable.h>
#include <stdlib.h>
#include <f_string/f_string.h>
#include <f_string/f_str_tools.h>

static void		uf_cell_delete(void *data)
{
	(void)data;
}

t_htable_cell	*f_htable_create_cell(const char *key, void *data,
									  void (*f_delete)(void *data))
{
	t_htable_cell	*cell;

	cell = malloc(sizeof(*cell));
	if (cell != NULL)
	{
		cell->v_key = uf_strdup(key);
		if (cell->v_key == NULL)
		{
			free(cell);
			return (NULL);
		}
		cell->v_data = data;
		cell->f_delete = uf_cell_delete;
		if (f_delete != NULL)
			cell->f_delete = f_delete;
	}
	return (cell);
}
void			f_htable_delete_cell(void *data)
{
	t_htable_cell	*cell;

	cell = (t_htable_cell*)data;
	free(cell->v_key);
	cell->f_delete(cell->v_data);
	free(cell);
}

ui				f_htable_generate_key(const t_htable *v_this, const char *str)
{
	ui	ret;
	ui	len;
	ui	i;
	ui	tmp;

	i = 0;
	ret = 0;
	len = uf_str_len(str);
	while (i < len)
	{
		ret = (ret << 4) + str[i];
		tmp = ret & 0xF0000000;
		if (tmp == 1)
		{
			ret = ret ^ (tmp >> 24);
			ret = ret ^ tmp;
		}
		i = i + 1;
	}
	return (ret % v_this->v_prime);
}

