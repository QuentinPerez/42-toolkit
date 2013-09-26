/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 13:26:45 by qperez            #+#    #+#             */
/*   Updated: 2013/09/26 13:52:47 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_memory/f_memory.h>
#include <f_string/f_print.h>

struct		s_point
{
	int	x;
	int	y;
	int	z;
};

void	uf_print_point(struct s_point *p)
{
	uf_print_str("x: ");
	uf_print_nbr(p->x);
	uf_print_str(" y: ");
	uf_print_nbr(p->y);
	uf_print_str(" z: ");
	uf_print_nbr(p->z);
	uf_print_char('\n');
}

#include <string.h>

int		main(int argc, char const** argv)
{
	struct s_point	p1;
	struct s_point	p2;

	p1.x = 1;
	p1.y = 2;
	p1.z = 3;
	uf_print_str("p1 ");
	uf_print_point(&p1);
	uf_print_str("\nsetting p1 ...\n\n");
	uf_memset(&p1, '\0', sizeof(p1));
	uf_memset(&p2, '\0', sizeof(p2));
	uf_print_str("p1 ");
	uf_print_point(&p1);
	uf_print_str("p2 ");
	uf_print_point(&p2);
	uf_print_str("compare (p1 ?= p2) -> ");
	uf_print_nbr(uf_memcmp(&p1, &p2, sizeof(p1)));
	uf_print_str("\n\n");
	p1.x = 1;
	uf_print_str("p1 ");
	uf_print_point(&p1);
	uf_print_str("p2 ");
	uf_print_point(&p2);
	uf_print_str("compare (p1 ?= p2) -> ");
	uf_print_nbr(uf_memcmp(&p1, &p2, sizeof(p1)));
	uf_print_str("\n\ncopying p1 to p2 ...\n\n");
	uf_memcpy(&p2, &p1, sizeof(p1));
	uf_print_str("p1 ");
	uf_print_point(&p1);
	uf_print_str("p2 ");
	uf_print_point(&p2);
	uf_print_str("compare (p1 ?= p2) -> ");
	uf_print_nbr(uf_memcmp(&p1, &p2, sizeof(p1)));
	uf_print_str("\n");
	(void)argc;
	(void)argv;
	return (0);
}

