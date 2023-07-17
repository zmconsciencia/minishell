/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:27:32 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/17 10:53:05 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	put_error(void)
{
	ft_putstr_fd(" numeric argument required\n", 2);
	return (2);
}

//retorna o primeiro conjunto de numeros encontrados na string como int.
long long	ft_atoi(const char *nptr)
{
	long long	y;
	long		n;
	int			sign;

	y = 0;
	sign = 1;
	if (*nptr == 0 || \
		!ft_strncmp("-9223372036854775808", (char *)nptr, ft_strlen(nptr)))
		return (0);
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == 43 || *nptr == 45)
	{
		if (*nptr == 45)
			sign *= -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		n = y;
		y = y * 10 + *nptr - '0';
		if (y < n || has_non_numeric(nptr))
			put_error();
		nptr++;
	}
	return (y * sign);
}
