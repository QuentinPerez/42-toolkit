/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/13 12:48:51 by qperez            #+#    #+#             */
/*   Updated: 2013/09/13 14:11:27 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <s_error.h>
#include <unistd.h>
#include <fcntl.h>
#include <f_print_fd.h>

#include <stdio.h>

bool	f_error_init(t_error *v_this, const char *filename)
{
	if (filename == NULL)
	{
		v_this->v_fd = 2;
		return (true);
	}
	v_this->v_fd = open(filename, O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 0644);
	return (v_this->v_fd != -1);
}

char	fm_print_serr(t_error *v_this, const char *date, int line,
					  const char *file)
{
	uf_print_char_fd('[', v_this->v_fd);
	uf_print_str_fd(date, v_this->v_fd);
	uf_print_str_fd("] ", v_this->v_fd);
	uf_print_str_fd(file, v_this->v_fd);
	uf_print_str_fd(", line ", v_this->v_fd);
	uf_print_nbr_fd(line, v_this->v_fd);
	return (1);
}

void	fm_error_add(t_error *v_this, const char *error, const char *funct,
					char nothing)
{
	uf_print_str_fd(": ", v_this->v_fd);
	uf_print_str_fd(funct, v_this->v_fd);
	uf_print_str_fd("()\n\t\t→ ", v_this->v_fd);
	uf_print_str_fd(error, v_this->v_fd);
	uf_print_char_fd('\n', v_this->v_fd);
	(void)nothing;
}

void	f_error_destroy(t_error *v_this)
{
	if (v_this->v_fd > 2)
		close(v_this->v_fd);
}
