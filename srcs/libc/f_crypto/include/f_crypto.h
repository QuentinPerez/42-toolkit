/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_crypto.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/18 17:27:57 by qperez            #+#    #+#             */
/*   Updated: 2014/01/08 12:24:16 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains f_cryto prototype>
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

#ifndef F_CRYPTO_H
# define F_CRYPTO_H

# include <t_types.h>

void	uf_crypto_xor(void *data, const char *key, ui data_size);
void	uf_crypto_rot5(char *str);
void	uf_crypto_rot13(char *str);
void	uf_crypto_rot18(char *str);
void	uf_crypto_rot47(char *str);

#endif
