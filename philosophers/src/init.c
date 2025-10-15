/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:07:49 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/15 20:46:19 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*call_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	routine(philo);
	return (NULL);
}

void	call_philosophers(void)
{
	unsigned int	i;
	unsigned int	n;
	t_philo			*philos;

	i = -1;
	n = table()->n_philo;
	philos = table()->philos;
	while (++i < n)
	{
		if (pthread_create(&philos[i].philo, NULL, call_routine, &philos[i]))
			return (print_error(ERR_TCREATE));
		usleep(500);
	}
	i = -1;
	while (++i < n)
	{
		pthread_join(philos[i].philo, NULL);
		usleep(500);
	}
}

void	set_forks(void)
{
	unsigned int	i;
	unsigned int	n;

	i = -1;
	n = table()->n_philo;
	table()->start = what_time();
	while (++i < n)
	{
		table()->philos[i].id = i + 1;
		table()->philos[i].meals = 0;
		table()->philos[i].r_fork.fork = true;
		table()->philos[i].last_meal = table()->start;
		table()->philos[i].full = false;
		pthread_mutex_init(&table()->philos[i].r_fork.fork_lock, NULL);
		pthread_mutex_init(&table()->philos[i].philo_lock, NULL);
		if (i > 0)
			table()->philos[i].l_fork = &table()->philos[i - 1].r_fork;
		else if (i == 0)
			table()->philos[i].l_fork = &table()->philos[n - 1].r_fork;
	}
}

void	build_table(t_str *av, int ac)
{
	table()->n_philo = ft_atoi_parse(av[1]);
	table()->to_die = ft_atoi_parse(av[2]);
	table()->to_eat = ft_atoi_parse(av[3]);
	table()->to_sleep = ft_atoi_parse(av[4]);
	if (ac == 6)
		table()->meals = ft_atoi_parse(av[5]);
	else
		table()->meals = -1;
	if (table()->has_error)
		return (print_error(ERR_INPUT));
	if (table()->n_philo == 1)
		return (print_error(ERR_ALONE));
	if (table()->meals == 0)
		return ;
	table()->philos = (t_philo *)malloc(table()->n_philo * sizeof(t_philo));
	if (!table()->philos)
		return (print_error(ERR_ALLOC));
	table()->dead = false;
	table()->all_full = false;
	pthread_mutex_init(&table()->death_lock, NULL);
	pthread_mutex_init(&table()->print_lock, NULL);
	pthread_mutex_init(&table()->full_lock, NULL);
	set_forks();
	call_philosophers();
}
