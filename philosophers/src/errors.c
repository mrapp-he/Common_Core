/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 23:10:22 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/16 11:41:23 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(int error)
{
	if (error == ERR_INPUT)
		write(2, "Invalid Input!\n", 16);
	else if (error == ERR_ALLOC)
		write(2, "Allocation Failed!\n", 20);
	else if (error == ERR_ALONE)
		printf("0 1 %s", DIE_MSG);
	else if (error == ERR_TCREATE)
	{
		write(2, "Failed to create a thread!\n", 28);
		destroy_table();
	}
}
