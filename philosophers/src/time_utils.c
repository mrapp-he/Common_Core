/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 09:44:31 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/13 15:55:00 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ull	get_ms(t_time time)
{
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

t_ull	get_curr(t_time *time)
{
	gettimeofday(time, NULL);
	return (get_ms(*time));
}
