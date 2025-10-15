/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:12:35 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/15 20:35:50 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "philo.h"

typedef char*				t_str;
typedef pthread_t			t_thrd;
typedef pthread_mutex_t		t_mtx;
typedef unsigned long long	t_ull;
typedef struct timeval		t_time;

typedef struct s_fork
{
	t_mtx	fork_lock;
	bool	fork;
}	t_fork;

typedef struct s_philo
{
	t_ull			id;
	bool			full;
	int				meals;
	t_thrd			philo;
	t_fork			r_fork;
	t_fork			*l_fork;
	t_ull			last_meal;
	t_mtx			philo_lock;
}	t_philo;

typedef struct s_table
{
	bool			dead;
	int				meals;
	t_ull			start;
	t_ull			to_die;
	t_ull			to_eat;
	t_ull			n_philo;
	t_philo			*philos;
	t_ull			to_sleep;
	bool			all_full;
	bool			has_error;
	t_mtx			full_lock;
	t_mtx			death_lock;
	t_mtx			print_lock;
}	t_table;

#endif
