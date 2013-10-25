/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/25 15:16:37 by qperez            #+#    #+#             */
/*   Updated: 2013/10/25 17:05:13 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_string/f_print_fd.h>

void	uf_print_floating_nbr_fd(double nbr, ui digit, int fd)
{
	uf_print_nbr_fd((ssize_t)nbr, fd);
	uf_print_char_fd('.', fd);
	while (digit > 0)
	{
		nbr = nbr - (ssize_t)nbr;
		nbr = nbr * 10;
		uf_print_char_fd((ssize_t)nbr + '0', fd);
		digit = digit - 1;
	}
}

void	uf_print_floating_nbr(double nbr, ui digit)
{
	uf_print_floating_nbr_fd(nbr, digit, 1);
}
