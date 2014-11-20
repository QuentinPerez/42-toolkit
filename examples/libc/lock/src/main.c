/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 15:12:35 by qperez            #+#    #+#             */
/*   Updated: 2014/11/20 21:10:40 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lock/s_lock.h>
#include <stdio.h>

/*
 * This file is a little example of the t_lock structure
 */

typedef struct	s_share
{
	int	var1;
	int	var2;
}				t_share;

int	main(int argc, char const** argv)
{
	/*
	 * Create all threads you want
	 */
	t_share	private_share;
	t_lock	lock;
	t_share	*acces_share;

	dprintf(1, "Init lock\n");
	if (D_LOCK(init)(&lock, &private_share, e_lock_default) == false)
		return (1);
	/*
	 * safe access
	 */
	dprintf(1, "Lock variable\n");
	if (D_LOCK(lock)(&lock, (void **)&acces_share) == true)
	{
		acces_share->var1 = 1;
		/*
		 * treat variable
		 */
		D_LOCK(release)(&lock, (void **)&acces_share);
		/*
		 * if here you access at the variable, you will crash because
		 * acces_share == NULL
		 */
		dprintf(1, "Release variable\n");
	}
	D_LOCK(destroy)(&lock);
	dprintf(1, "Destroy lock\n");
	(void)argc;
	(void)argv;
	return (0);
}

