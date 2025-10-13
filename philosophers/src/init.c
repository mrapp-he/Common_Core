/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:07:49 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/13 19:55:17 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *)ptr;
	philo->last_meal = get_curr(&table()->curr_time);
	while (mutex_get(table()->dead_lock, &table()->dead, sizeof(bool)) == false
	&& mutex_get(table()->dead_lock, &table()->full_philos, sizeof(bool)) == false)
	{
		if (get_curr(&table()->curr_time) - philo->last_meal >= table()->to_die)
		{
			printf("| %lld | %d | died\n", get_curr(&table()->curr_time), philo->id);
			mutex_set(table()->dead_lock, &table()->dead, &(bool){true}, sizeof(bool));
			break ;
		}
		if (grab_forks(philo))
		{
			printf("| %lld | %d | has taken a fork\n", get_curr(&table()->curr_time), philo->id);
			printf("| %lld | %d | has taken a fork\n", get_curr(&table()->curr_time), philo->id);
			printf("| %lld | %d | is eating\n", get_curr(&table()->curr_time), philo->id);
			philo->last_meal = get_curr(&table()->curr_time);
			philo->meals++;
			if (table()->meals >= 0 && philo->meals >= table()->meals)
				mutex_set(philo->r_fork.fork_lock, &philo->full, &(bool){true}, sizeof(bool));
			are_they_full();
			if (mutex_get(table()->dead_lock, &table()->full_philos, sizeof(bool)) == true)
				break ;
			usleep(table()->to_eat * 1000);
			release_forks(philo);
			if (mutex_get(table()->dead_lock, &table()->dead, sizeof(bool)) == false
			&& mutex_get(table()->dead_lock, &table()->full_philos, sizeof(bool)) == false)
			{
				printf("| %lld | %d | is sleeping\n", get_curr(&table()->curr_time), philo->id);
				usleep(table()->to_sleep * 1000);
				if (mutex_get(table()->dead_lock, &table()->dead, sizeof(bool)) == false
				&& mutex_get(table()->dead_lock, &table()->full_philos, sizeof(bool)) == false)
					printf("| %lld | %d | is thinking\n", get_curr(&table()->curr_time), philo->id);
			}
		}
		else
			usleep(1000);
	}
	return NULL;
}

void	call_philosophers(void)
{
	unsigned int	i;
	unsigned int	n;
	
	i = -1;
	n = table()->n_philo;
	while (++i < n)
	{
		pthread_create(&table()->philos[i].philo, NULL, routine, &table()->philos[i]);
		usleep(500);
	}
	i = -1;
	while (++i < n)
	{
		pthread_join(table()->philos[i].philo, NULL);
		usleep(500);
	}
}

void	set_forks(void)
{
	unsigned int	i;
	unsigned int	n;

	i = -1;
	n = table()->n_philo;
	while (++i < n)
	{
		table()->philos[i].id = i + 1;
		table()->philos[i].r_fork.fork = true;
		pthread_mutex_init(&table()->philos[i].r_fork.fork_lock, NULL);
		if (i > 0)
			table()->philos[i].l_fork = &table()->philos[i - 1].r_fork;
		else if (i == 0)
			table()->philos[i].l_fork = &table()->philos[n - 1].r_fork;
	}
}

void	build_table(t_str *av, int ac)
{
	table()->n_philo = ft_atoi(av[1]);
	table()->to_die = ft_atoi(av[2]);
	table()->to_eat = ft_atoi(av[3]);
	table()->to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table()->meals = ft_atoi(av[5]);
	else
		table()->meals = -1;
	gettimeofday(&table()->curr_time, NULL);
	table()->philos = (t_philo *)malloc(table()->n_philo * sizeof(t_philo));
	if (!table()->philos)
		exit(1);
	pthread_mutex_init(&table()->dead_lock, NULL);
	set_forks();
	call_philosophers();
}
