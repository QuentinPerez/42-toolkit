/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/08 13:01:24 by qperez            #+#    #+#             */
/*   Updated: 2013/10/08 14:03:42 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <hashtable/s_htable.h>

int	main(int argc, char const** argv)
{
	t_htable	htable;

	D_HTABLE(init)(&htable, NULL);
	D_HTABLE(destroy)(&htable);
	(void)argc;
	(void)argv;
	return (0);
}

