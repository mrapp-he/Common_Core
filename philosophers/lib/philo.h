/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 22:54:16 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/13 19:37:26 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#  include <stdio.h>
#  include <stdlib.h>
#  include <string.h>
#  include <unistd.h>
#  include <pthread.h>
#  include <stdbool.h>
#  include <sys/time.h>

#  define ERR_IN 0
#  define HERE printf("HERE\n")
#  define THERE printf("THERE\n")

typedef char*				t_str;
typedef	pthread_t			t_thrd;
typedef pthread_mutex_t		t_mtx;
typedef unsigned long long	t_ull;
typedef	struct timeval		t_time;

typedef struct	s_fork
{
	t_mtx	fork_lock;
	bool	fork;
}	t_fork;

typedef struct	s_philo
{
	unsigned int	id;
	int				meals;
	bool			full;
	t_thrd			philo;
	t_fork			r_fork;
	t_fork			*l_fork;
	t_ull			last_meal;
}	t_philo;

typedef	struct	s_table
{
	bool			dead;
	int				meals;
	unsigned int	to_die;
	unsigned int	to_eat;
	unsigned int	n_philo;	
	t_philo			*philos;
	unsigned int	to_sleep;
	t_time			curr_time;
	t_mtx			dead_lock;
	bool			full_philos;
}	t_table;

void	mutex_set(t_mtx mutex, void *var, void *val, t_ull size);
int		ft_memcmp(const void *mem1, const void *mem2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
t_ull	mutex_get(t_mtx mutex, void *var, t_ull size);
void	build_table(t_str *av, int ac);
void	release_forks(t_philo *philo);
int		grab_forks(t_philo *philo);
int		ft_atoi(const char *nbr);
void	print_error(int error);
t_ull	get_curr(t_time *time);
void	are_they_full(void);
t_ull	get_ms(t_time time);
t_table	*table(void);

#endif
