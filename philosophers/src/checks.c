/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:21:57 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/13 19:44:15 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	are_they_full(void)
{
	unsigned int	i;
	unsigned int	n;
	unsigned int	f;
	t_mtx			full;
	t_philo			*philo;

	i = -1;
	f = 0;
	n = table()->n_philo;
	philo = table()->philos;
	pthread_mutex_init(&full, NULL);
	while (++i < n)
	{
		if (mutex_get(full, &philo[i].full, sizeof(bool)) == true)
			f++;
	}
	if (f == n)
		mutex_set(full, &table()->full_philos, &(bool){true}, sizeof(bool));
	pthread_mutex_destroy(&full);
}
