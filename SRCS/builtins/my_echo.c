/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:09:55 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/14 22:22:24 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_echo(char **flags)
{
	int	i;

	i = 1;
	if (flags[i])
	{
		if (!ft_strncmp(flags[i], "-n\0", 2))
			i = 2;
		while (flags[i])
		{
			printf("%s", flags[i]);
			if (flags[++i])
				printf(" ");
		}
		if (ft_strncmp(flags[1], "-n\0", 2))
			printf("\n");
	}
	else
		printf("\n");
	return (1); //o original retorna 0 em sucesso
}
