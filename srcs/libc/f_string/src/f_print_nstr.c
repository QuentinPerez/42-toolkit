/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_nstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/30 11:19:07 by qperez            #+#    #+#             */
/*   Updated: 2013/10/30 11:22:09 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <t_types.h>
#include <unistd.h>

ssize_t	uf_print_nstr_fd(const char *str, ui size, ui fd)
{
	return (write(fd, str, size));
}

void	uf_print_nstr(const char *str, ui size)
{
	uf_print_nstr_fd(str, size, 1);
}
