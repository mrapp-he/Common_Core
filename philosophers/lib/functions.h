/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:14:16 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/15 20:13:40 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "philo.h"

void	mutex_set(t_mtx *mutex, bool *var, bool val);
void	narrate_action(t_philo *philo, int message);
void	ft_usleep(t_philo *philo, t_ull ms);
bool	mutex_get(t_mtx *mutex, bool *var);
void	build_table(t_str *av, int ac);
void	set_last_meal(t_philo *philo);
void	release_forks(t_philo *philo);
int		ft_strcmp(t_str s1, t_str s2);
bool	time_to_die(t_philo *philo);
int		grab_forks(t_philo *philo);
t_ull	ft_atoi_parse(t_str	input);
void	routine(t_philo *philo);
void	print_error(int error);
bool	end_simulation(void);
void	are_they_full(void);
void	destroy_table(void);
t_ull	what_time(void);
t_table	*table(void);

#endif
