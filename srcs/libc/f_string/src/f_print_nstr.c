/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_nstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/30 11:19:07 by qperez            #+#    #+#             */
/*   Updated: 2015/07/03 16:37:01 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <f_string/f_print.h>
#include <f_string/f_print_fd.h>

ssize_t	uf_print_nstr_fd(const char *str, size_t size, int fd)
{
	return (write(fd, str, size));
}

void	uf_print_nstr(const char *str, size_t size)
{
	uf_print_nstr_fd(str, size, 1);
}
