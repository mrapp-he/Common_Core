/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 22:53:36 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/13 19:38:06 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*table(void)
{
	static t_table	table;

	return (&table);
}

int	main(int ac, t_str *av)
{
	unsigned int	i;
	unsigned int	n;

	i = -1;
	if (ac < 5 || ac > 6)
		return (print_error(ERR_IN), 1);
	build_table(av, ac);
	n = table()->n_philo;
	pthread_mutex_destroy(&table()->dead_lock);
	while (++i < n)
		pthread_mutex_destroy(&table()->philos[i].r_fork.fork_lock);
	return (0);
}