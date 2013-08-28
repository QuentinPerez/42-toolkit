/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_fd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 15:11:46 by qperez            #+#    #+#             */
/*   Updated: 2013/08/28 15:12:36 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_PRINT_H
# define F_PRINT_H

#include <unistd.h>

ssize_t	uf_print_char_fd(char c, int fd);
ssize_t	uf_print_str_fd(const char *str, int fd);
void	uf_print_nbr_fd(ssize_t nb, int fd);

#endif
