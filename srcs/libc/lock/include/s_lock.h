/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_lock.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:21:07 by qperez            #+#    #+#             */
/*   Updated: 2014/03/19 15:05:53 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_LOCK_H
# define S_LOCK_H

# include <pthread.h>
# include <stdbool.h>

typedef struct	s_lock
{
	void				*data;
	pthread_mutex_t		lock;
}				t_lock;

# define D_LOCK(funct)				f_lock_##funct

bool	f_lock_init(t_lock *v_this, void *data);
bool	f_lock_lock(t_lock *v_this, void **data);
bool	f_lock_release(t_lock *v_this, void **data);
bool	f_lock_destroy(t_lock *v_this);

#endif /* !S_LOCK_H */
