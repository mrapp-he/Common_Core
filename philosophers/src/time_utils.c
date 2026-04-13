/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 09:44:31 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/15 20:29:27 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_usleep(philo, 1);
	while (!end_simulation())
	{
		if (grab_forks(philo))
		{
			if (time_to_die(philo))
				break ;
			narrate_action(philo, EAT);
			ft_usleep(philo, table()->to_eat);
			if (time_to_die(philo))
				break ;
			release_forks(philo);
			if (time_to_die(philo))
				break ;
			narrate_action(philo, SLEEP);
			if (time_to_die(philo))
				break ;
			narrate_action(philo, THINK);
			continue ;
		}
		usleep(100);
		if (time_to_die(philo))
			break ;
	}
}

void	ft_usleep(t_philo *philo, t_ull ms)
{
	t_ull	current;
	t_ull	start;

	start = what_time();
	current = start;
	while (current - start < ms)
	{
		if (time_to_die(philo))
			break ;
		usleep(100);
		current = what_time();
	}
}

t_ull	what_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

bool	time_to_die(t_philo *philo)
{
	t_ull	current;
	t_ull	last;
	bool	must_die;

	current = what_time();
	pthread_mutex_lock(&philo->philo_lock);
	last = philo->last_meal;
	pthread_mutex_unlock(&philo->philo_lock);
	must_die = (current - last >= table()->to_die);
	if (must_die)
	{
		pthread_mutex_lock(&table()->death_lock);
		if (!table()->dead)
		{
			table()->dead = true;
			pthread_mutex_unlock(&table()->death_lock);
			narrate_action(philo, DIE);
			return (true);
		}
		pthread_mutex_unlock(&table()->death_lock);
	}
	return (false);
}
