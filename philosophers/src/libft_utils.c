/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 23:09:52 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/13 18:33:37 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nbr)
{
	int	res;
	int	sgn;

	res = 0;
	sgn = 1;
	while (*nbr == ' ' || (*nbr >= '\t' && *nbr <= '\r'))
		nbr++;
	if (*nbr == '+' || *nbr == '-')
	{
		sgn = (*nbr == '+') - (*nbr == '-');
		nbr++;
	}
	while (*nbr >= '0' && *nbr <= '9')
	{
		res = (res * 10) + (*nbr - '0');
		nbr++;
	}
	return (res * sgn);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*start;

	start = dest;
	if (!dest && !src)
		return (NULL);
	while (n--)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (start);
}

int	ft_memcmp(const void *mem1, const void *mem2, size_t n)
{
	unsigned char	*temp_mem1;
	unsigned char	*temp_mem2;

	temp_mem1 = (unsigned char *)mem1;
	temp_mem2 = (unsigned char *)mem2;
	while (n--)
	{
		if (*temp_mem1 != *temp_mem2)
			return (*temp_mem1 - *temp_mem2);
		temp_mem1++;
		temp_mem2++;
	}
	return (0);
}
