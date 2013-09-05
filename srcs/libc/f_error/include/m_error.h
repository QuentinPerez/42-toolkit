/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_error.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 12:24:04 by qperez            #+#    #+#             */
/*   Updated: 2013/08/28 12:30:30 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains all m_error prototype>
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

#ifndef M_ERROR_H
# define M_ERROR_H

#include <stddef.h>

# define D_PRINT_INFOS			fm_print_infos(__FILE__, __LINE__, __func__)
# define m_error(str_err, ret)	fm_error(D_PRINT_INFOS, str_err, ret)
# define m_error_v(str_err)		fm_error_v(D_PRINT_INFOS, str_err)
# define m_infos(str_inf)		fm_infos(__func__, str_inf)

char	fm_print_infos(const char *file, int line, const char *fct);
size_t	fm_error(char call_print_infos, const char *err, size_t ret);
void	fm_error_v(char call_print_infos, const char *err);
void	fm_infos(const char *infos, const char *err);

#endif
