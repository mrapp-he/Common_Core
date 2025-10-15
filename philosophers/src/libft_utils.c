/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 23:09:52 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/15 20:13:00 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ull	ft_atoi_parse(t_str	input)
{
	t_ull	res;
	t_ull	i;

	res = 0;
	i = 0;
	while (input[i] == ' ' || (input[i] >= '\t' && input[i] <= '\r'))
		i++;
	if (input[i] == '+' || input[i] == '-')
	{
		if (input[i] == '-')
			table()->has_error = true;
		i++;
	}
	while (input[i] >= '0' && input[i] <= '9')
	{
		res = (res * 10) + (input[i] - '0');
		i++;
	}
	if (input[i])
		table()->has_error = true;
	return (res);
}

int	ft_strcmp(t_str s1, t_str s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
