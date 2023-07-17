/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:27:32 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/17 16:05:44 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	return_sign(const char *nptr)
{
	int	sign;

	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == 45)
		sign *= -1;
	return (sign);
}

long long	ft_atoi(const char *nptr)
{
	long long	y;
	long		n;
	int			sign;

	y = 0;
	sign = return_sign(nptr);
	if (*nptr == 0 || \
		!ft_strncmp("-9223372036854775808", (char *)nptr, ft_strlen(nptr)))
		return (0);
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32 || \
		*nptr == 45 || *nptr == 43)
		nptr++;
	while (*nptr >= 48 && *nptr <= 57)
	{
		n = y;
		y = y * 10 + *nptr - '0';
		if (y < n || has_non_numeric(nptr))
		{
			ft_putstr_fd(" numeric argument required\n", 2);
			return (2);
		}
		nptr++;
	}
	return (y * sign);
}
