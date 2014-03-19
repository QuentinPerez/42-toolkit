/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_lock.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:20:45 by qperez            #+#    #+#             */
/*   Updated: 2014/03/19 15:06:37 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lock/s_lock.h>
#include <f_error/m_error.h>

bool	f_lock_init(t_lock *v_this, void *data)
{
	if (pthread_mutex_init(&v_this->lock, NULL) != 0)
		return (M_ERROR(false, "Fail init lock"));
	v_this->data = data;
	return (true);
}

bool	f_lock_lock(t_lock *v_this, void **data)
{
	if (pthread_mutex_lock(&v_this->lock) != 0)
		return (M_ERROR(false, "Bad lock"));
	*data = v_this->data;
	return (true);
}

bool	f_lock_destroy(t_lock *v_this)
{
	return (!(pthread_mutex_destroy(&v_this->lock) != 0));
}

bool	f_lock_release(t_lock *v_this, void **data)
{
	if (pthread_mutex_unlock(&v_this->lock) != 0)
		return (M_ERROR(false, "Fail unlock"));
	*data = NULL;
	return (true);
}
