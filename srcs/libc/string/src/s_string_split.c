/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/28 20:37:37 by qperez            #+#    #+#             */
/*   Updated: 2014/12/02 11:33:06 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_string_split function>
** < split >
** Copyright (C) <2013>  Quentin Perez <qperez42@gmail.com>
** This file is part of 42-toolkit.
** 42-toolkit is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <f_secure/f_secure.h>
#include <stdint.h>
#include <f_error/m_error.h>
#include <string/s_string.h>
#include <f_memory/f_memory.h>
#include <f_string/f_str_tools.h>
#include <f_string/f_string.h>
#include <f_memory/f_free.h>

static bool	*uf_string_fill_bool(t_string *v_this, const char *charset)
{
	size_t	i;
	size_t	size;
	bool	*active;

	i = 0;
	if ((active = uf_malloc_s(v_this->v_size, sizeof(*active))) == NULL)
		return ((bool *)M_ERROR((size_t)NULL, "Bad alloc"));
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

static size_t	uf_string_count_word(t_string *v_this, bool *active)
{
	size_t	i;
	size_t	word;

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

static bool	uf_string_dump_word(const char *str, char **tab,
								size_t size, size_t *word)
{
	if ((tab[*word] = uf_malloc_s(size + 1, sizeof(*tab[*word]))) == NULL)
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
	size_t	i;
	size_t	size;
	size_t	word;

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
	size_t	nb_word;

	if (v_this->v_size == 0)
		return (NULL);
	active = uf_string_fill_bool(v_this, charset);
	if (active == NULL)
		return (NULL);
	nb_word = uf_string_count_word(v_this, active);
	if ((ret = uf_malloc_s(nb_word, sizeof(*ret))) == NULL)
	{
		uf_free_s((void **)&active);
		return (NULL);
	}
	if (uf_string_fill_tab(v_this, ret, active) == false)
		ret = NULL;
	uf_free_s((void **)&active);
	return (ret);
}
