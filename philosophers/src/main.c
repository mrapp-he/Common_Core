/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 22:53:36 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/14 11:20:56 by mrapp-he         ###   ########.fr       */
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
	if (ac < 5 || ac > 6)
		return (print_error(ERR_INPUT), 1);
	build_table(av, ac);
	destroy_table();
	return (0);
}
