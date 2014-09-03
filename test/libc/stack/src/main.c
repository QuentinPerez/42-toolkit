/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2014/09/03 16:52:09 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack/s_stack.h>
#include <unit/s_unit.h>

void	D_UNIT_FUNCT(memleaks)
{
	unsigned int	i;
	t_stack			stack;

	i = 0;
	D_STACK(init)(&stack, 0);
	while (i < 5000)
	{
		D_UNIT(assert)(D_STACK(push)(&stack, 0) == true);
		i = i + 1;
	}
	D_UNIT(assert)(D_STACK(size)(&stack) == 5000);
	D_STACK(destroy)(&stack);
}

int		main(int argc, char const** argv)
{
	t_unit	unit;

	D_UNIT(init)(&unit);
	D_UNIT(add_context)(&unit, "Leaks", 0, 0);
	D_UNIT(add_test)(&unit, "Leaks", memleaks);
	D_UNIT(console_run)(&unit);
	D_UNIT(destroy)(&unit);
	(void)argc;
	(void)argv;
	return (0);
}
