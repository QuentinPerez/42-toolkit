/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/22 12:13:53 by qperez            #+#    #+#             */
/*   Updated: 2013/10/29 23:00:11 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STRING_H
# define S_STRING_H

#include <d_bool.h>
#include <t_types.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct	s_string
{
	char		*v_str;
	ui			v_size;
	ui			v_capacity;
	const char	*v_hex;
	ui			(*f_realloc)(ui size);
}				t_string;

# define D_STRING(funct)	f_string_##funct

bool	f_string_init(t_string *v_this, ui (*uf_realloc)(ui size));
void	f_string_print(t_string *v_this);
void	f_string_print_fd(t_string *v_this, ui fd);
void	f_string_print_memory(t_string *v_this, const char *name);
char	*f_string_dup(t_string *v_this);
ui		f_string_capacity(t_string *v_this);
bool	f_string_empty(t_string *v_this);
ui		f_string_size(t_string *v_this);
void	f_string_clear(t_string *v_this);
bool	f_string_add_str(t_string *v_this, const char *str);
bool	f_string_add_nstr(t_string *v_this, const char *str, ui size);
bool	f_string_add_char(t_string *v_this, uc c);
bool	f_string_add_nbr(t_string *v_this, ssize_t nbr);
bool	f_string_add_ptr(t_string *v_this, void *addr);
bool	f_string_add_nbr_base(t_string *v_this, ssize_t nbr, ui base);
bool	f_string_variadic(t_string *v_this, const char *fmt, ...);
bool	f_string_variadic_list(t_string *v_this, const char *fmt, va_list *ap);
char	**f_string_split(t_string *v_this, const char *charset);
void	f_string_erase(t_string *v_this, ui from, ui to);
bool	f_string_insert(t_string *v_this, const char *insert, ui at);
void	f_string_destroy(t_string *v_this);

#endif
