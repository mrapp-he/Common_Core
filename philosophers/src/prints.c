/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 23:01:07 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/15 20:33:40 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_print(t_mtx *mutex, int id, t_str msg)
{
	t_ull	time;
	bool	is_dead;

	pthread_mutex_lock(mutex);
	time = what_time() - table()->start;
	pthread_mutex_lock(&table()->death_lock);
	is_dead = table()->dead;
	pthread_mutex_unlock(&table()->death_lock);
	if (!is_dead || !ft_strcmp(msg, DIE_MSG))
		printf("%lld %d %s", time, id, msg);
	pthread_mutex_unlock(mutex);
}

void	set_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_lock);
	philo->last_meal = what_time();
	pthread_mutex_unlock(&philo->philo_lock);
}

void	has_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_lock);
	philo->meals++;
	if (table()->meals >= 0 && philo->meals >= table()->meals)
		philo->full = true;
	pthread_mutex_unlock(&philo->philo_lock);
}

void	narrate_action(t_philo *philo, int message)
{
	if (time_to_die(philo))
		return ;
	if (message == EAT)
	{
		mutex_print(&table()->print_lock, philo->id, FORK_MSG);
		mutex_print(&table()->print_lock, philo->id, FORK_MSG);
		set_last_meal(philo);
		mutex_print(&table()->print_lock, philo->id, EAT_MSG);
		has_eaten(philo);
		are_they_full();
	}
	else if (message == DIE)
		mutex_print(&table()->print_lock, philo->id, DIE_MSG);
	else if (message == SLEEP)
	{
		mutex_print(&table()->print_lock, philo->id, SLEEP_MSG);
		ft_usleep(philo, table()->to_sleep);
	}
	else if (message == THINK)
	{
		mutex_print(&table()->print_lock, philo->id, THINK_MSG);
		ft_usleep(philo, 1);
	}
}
