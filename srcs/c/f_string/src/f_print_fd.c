/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 15:06:45 by qperez            #+#    #+#             */
/*   Updated: 2013/08/28 15:39:31 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_print_fd.h>
#include <f_str_tools.h>

ssize_t	uf_print_char_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

ssize_t	uf_print_str_fd(const char *str, int fd)
{
	return (write(fd, str, uf_str_len(str)));
}

void	uf_print_nbr_fd(ssize_t nbr, int fd)
{
	ssize_t	digit;

	digit = 1;
	while ((nbr / digit) >= 10 || (nbr / digit) <= -10)
		digit = digit * 10;
	if (nbr < 0)
		uf_print_char_fd('-', fd);
	while (digit > 0)
	{
		if (nbr < 0)
			uf_print_char_fd(nbr / digit % 10 * - 1 + '0', fd);
		else
			uf_print_char_fd(nbr / digit % 10 + '0', fd);
		digit = digit / 10;
	}
}
