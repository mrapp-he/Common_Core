/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:21:57 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/15 18:06:10 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	are_they_full(void)
{
	bool			is_full;
	unsigned int	i;
	unsigned int	f;
	t_philo			*philo;

	i = -1;
	f = 0;
	philo = table()->philos;
	is_full = false;
	pthread_mutex_lock(&table()->full_lock);
	if (table()->all_full == false)
	{
		while (++i < table()->n_philo)
		{
			pthread_mutex_lock(&philo[i].philo_lock);
			is_full = philo[i].full;
			pthread_mutex_unlock(&philo[i].philo_lock);
			if (is_full == true)
				f++;
		}
		if (f == table()->n_philo)
			table()->all_full = true;
	}
	pthread_mutex_unlock(&table()->full_lock);
}

bool	end_simulation(void)
{
	if (mutex_get(&table()->death_lock, &table()->dead))
		return (true);
	else if (mutex_get(&table()->full_lock, &table()->all_full))
		return (true);
	return (false);
}
