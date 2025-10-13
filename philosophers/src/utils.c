/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:06:26 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/13 19:06:32 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_set(t_mtx mutex, void *var, void *val, t_ull size)
{
	pthread_mutex_lock(&mutex);
	ft_memcpy(var, val, size);
	pthread_mutex_unlock(&mutex);

}

t_ull	mutex_get(t_mtx mutex, void *var, t_ull size)
{
	t_ull	ret;

	ret = 0;
	pthread_mutex_lock(&mutex);
	ft_memcpy(&ret, var, size);
	pthread_mutex_unlock(&mutex);
	return (ret);
}

bool	try_grab(t_fork *fork, void *check, void *new, t_ull size)
{
	bool	ret;

	ret = false;
	pthread_mutex_lock(&fork->fork_lock);
	if (!ft_memcmp(&fork->fork, check, size))
	{
		ft_memcpy(&fork->fork, new, size);
		ret = true;
	}
	pthread_mutex_unlock(&fork->fork_lock);
	return (ret);
}

int	grab_forks(t_philo *philo)
{
	t_fork	*first;
	t_fork	*second;

	if (philo->id % 2 == 0)
		first = &philo->r_fork;
	else
		first = philo->l_fork;
	if (philo->id % 2 == 0)
		second = philo->l_fork;
	else
		second = &philo->r_fork;
	if (try_grab(first, &(bool){true}, &(bool){false}, sizeof(bool)) == true)
	{
		if (try_grab(second, &(bool){true}, &(bool){false}, sizeof(bool)) == true)
			return (1);
		else
			mutex_set(first->fork_lock, &first->fork, &(bool){true}, sizeof(bool));
	}
	return (0);
}

void	release_forks(t_philo *philo)
{
	mutex_set(philo->r_fork.fork_lock, &philo->r_fork.fork, &(bool){true}, sizeof(bool));
	mutex_set(philo->l_fork->fork_lock, &philo->l_fork->fork, &(bool){true}, sizeof(bool));
}