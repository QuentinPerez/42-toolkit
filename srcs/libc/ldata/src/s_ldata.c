/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ldata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/05 11:48:32 by qperez            #+#    #+#             */
/*   Updated: 2015/04/09 15:27:41 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains ldata method>
** < init, destroy >
** Copyright (C) <2015>  Quentin Perez <qperez42@gmail.com>
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

#include <ldata/s_ldata.h>
#include <f_error/m_error.h>
#include <sys/resource.h>
#include <f_secure/f_secure.h>
#include <f_memory/f_memory.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>

bool	f_ldata_init(t_ldata *v_this, size_t len)
{
	struct rlimit	rlp;

	rlp.rlim_cur = 0;
	rlp.rlim_max = 0;
	v_this->v_len = 0;
	v_this->v_ptr = NULL;
	errno = 0;
	if (setrlimit(RLIMIT_CORE, &rlp) == -1)
		return (M_ERROR(false, "setrlimit: %s", strerror(errno)));
	if ((v_this->v_ptr = uf_calloc_s(1, len)) == NULL)
		return (M_ERROR(false, "Bad alloc"));
	uf_memset(v_this->v_ptr, 0, len);
	if (mlock(v_this->v_ptr, len) == -1)
	{
		uf_free_s((void **)&v_this->v_ptr);
		return (M_ERROR(false, "mlock: %s", strerror(errno)));
	}
	v_this->v_len = len;
	return (true);
}

void	*f_ldata_get_ptr(t_ldata *v_this)
{
	return (v_this->v_ptr);
}

void	f_ldata_destroy(t_ldata *v_this)
{
	if (v_this->v_len != 0)
	{
		uf_free_s((void **)&v_this->v_ptr);
		if (munlock(v_this->v_ptr, v_this->v_len) == -1)
			M_ERROR(0, "mlock: %s", strerror(errno));
	}
	v_this->v_len = 0;
}
