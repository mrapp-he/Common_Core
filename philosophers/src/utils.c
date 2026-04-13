/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:06:26 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/15 19:00:09 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_set(t_mtx *mutex, bool *var, bool val)
{
	pthread_mutex_lock(mutex);
	*var = val;
	pthread_mutex_unlock(mutex);
}

bool	mutex_get(t_mtx *mutex, bool *var)
{
	bool	ret;

	ret = false;
	pthread_mutex_lock(mutex);
	ret = *var;
	pthread_mutex_unlock(mutex);
	return (ret);
}

bool	try_grab(t_mtx *mutex, t_fork *fork, bool check, bool new)
{
	bool	ret;

	ret = false;
	pthread_mutex_lock(mutex);
	if (fork->fork == check)
	{
		fork->fork = new;
		ret = true;
	}
	pthread_mutex_unlock(mutex);
	return (ret);
}

int	grab_forks(t_philo *philo)
{
	t_fork	*first;
	t_fork	*second;

	if (philo->id % 2 == 0)
	{
		first = &philo->r_fork;
		second = philo->l_fork;
	}
	else
	{
		first = philo->l_fork;
		second = &philo->r_fork;
	}
	if (try_grab(&first->fork_lock, first, true, false))
	{
		if (try_grab(&second->fork_lock, second, true, false))
			return (1);
		mutex_set(&first->fork_lock, &first->fork, true);
	}
	return (0);
}

void	release_forks(t_philo *philo)
{
	t_mtx	*right;
	t_mtx	*left;

	right = &philo->r_fork.fork_lock;
	left = &philo->l_fork->fork_lock;
	mutex_set(right, &philo->r_fork.fork, true);
	mutex_set(left, &philo->l_fork->fork, true);
}
