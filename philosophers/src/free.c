/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:59:15 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/15 20:03:04 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_forks(void)
{
	unsigned int	i;
	unsigned int	n;

	if (!table()->philos)
		return ;
	i = -1;
	n = table()->n_philo;
	while (++i < n)
	{
		pthread_mutex_destroy(&table()->philos[i].r_fork.fork_lock);
		pthread_mutex_destroy(&table()->philos[i].philo_lock);
	}
}

void	kill_philosophers(void)
{
	if (table()->philos)
		free(table()->philos);
}

void	destroy_table(void)
{
	clean_forks();
	kill_philosophers();
	pthread_mutex_destroy(&table()->death_lock);
	pthread_mutex_destroy(&table()->print_lock);
	pthread_mutex_destroy(&table()->full_lock);
}
