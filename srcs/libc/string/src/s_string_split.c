/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/28 20:37:37 by qperez            #+#    #+#             */
/*   Updated: 2013/11/10 17:36:43 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_string_split function>
** < split >
** Copyright (C) <2013>  Quentin Perez <qperez42@gmail.com>
**
** This file is part of 42-toolkit.
**
** 42-toolkit is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdlib.h>
#include <f_error/m_error.h>
#include <string/s_string.h>
#include <f_memory/f_memory.h>
#include <f_string/f_str_tools.h>
#include <f_string/f_string.h>
#include <f_memory/f_free.h>

static bool	*uf_string_fill_bool(t_string *v_this, const char *charset)
{
	ui		i;
	ui		size;
	bool	*active;

	i = 0;
	active = malloc(v_this->v_size * sizeof(*active));
	if (active == NULL)
		return ((bool *)m_error((size_t)NULL, "Bad alloc"));
	uf_memset(active, false, v_this->v_size * sizeof(*active));
	size = uf_str_len(charset);
	if (size == 0)
		i = v_this->v_size;
	while (i < v_this->v_size)
	{
		if (uf_strncmp(v_this->v_str + i, charset, size) == 0)
		{
			uf_memset(active + i, true, size * sizeof(*active));
			i = i + size;
		}
		else
			i = i + 1;
	}
	return (active);
}

static ui	uf_string_count_word(t_string *v_this, bool *active)
{
	ui	i;
	ui	word;

	i = 0;
	word = 0;
	while (i < v_this->v_size && active[i] == true)
		i = i + 1;
	while (i < v_this->v_size)
	{
		word = word + 1;
		while (i < v_this->v_size && active[i] == false)
			i = i + 1;
		while (i < v_this->v_size && active[i] == true)
			i = i + 1;
	}
	return (word + 1);
}

static bool	uf_string_dump_word(const char *str, char **tab, ui size, ui *word)
{
	ui	i;

	i = 0;
	tab[*word] = malloc(sizeof(*tab[*word]) * (size + 1));
	if (tab[*word] == NULL)
	{
		uf_free_tab_fail((void **)tab, *word);
		return (false);
	}
	uf_memcpy(tab[*word], str, size * sizeof(*tab[*word]));
	tab[*word][size] = '\0';
	*word = *word + 1;
	tab[*word] = NULL;
	return (true);
}

static bool	uf_string_fill_tab(t_string *v_this, char **tab, bool *active)
{
	ui	i;
	ui	size;
	ui	word;

	i = 0;
	word = 0;
	while (i < v_this->v_size && active[i] == true)
		i = i + 1;
	while (i < v_this->v_size)
	{
		size = 0;
		while (i < v_this->v_size && active[i] == false)
		{
			i = i + 1;
			size = size + 1;
		}
		if (uf_string_dump_word(v_this->v_str + i - size,
								tab, size, &word) == false)
			return (false);
		while (i < v_this->v_size && active[i] == true)
			i = i + 1;
	}
	return (true);
}

char		**f_string_split(t_string *v_this, const char *charset)
{
	bool	*active;
	char	**ret;

	if (v_this->v_size == 0)
		return (NULL);
	active = uf_string_fill_bool(v_this, charset);
	if (active == NULL)
		return (NULL);
	ret = malloc(sizeof(*ret) * uf_string_count_word(v_this, active));
	if (ret != NULL && uf_string_fill_tab(v_this, ret, active) == false)
		ret = NULL;
	free(active);
	return (ret);
}
