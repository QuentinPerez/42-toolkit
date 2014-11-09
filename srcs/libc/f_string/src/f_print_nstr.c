/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_nstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/30 11:19:07 by qperez            #+#    #+#             */
/*   Updated: 2014/02/12 19:38:10 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ssize_t	uf_print_nstr_fd(const char *str, size_t size, int fd)
{
	return (write(fd, str, size));
}

void	uf_print_nstr(const char *str, size_t size)
{
	uf_print_nstr_fd(str, size, 1);
}
