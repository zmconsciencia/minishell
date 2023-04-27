/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:09:55 by bde-seic          #+#    #+#             */
/*   Updated: 2023/04/26 20:17:25 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_echo(char **quoted_line)
{
	int	i;

	i = 1;
	if (quoted_line[i])
	{
		if (!ft_strncmp(quoted_line[i], "-n\0", 2))
			i = 2;
		while (quoted_line[i])
		{
			printf("%s", quoted_line[i]);
			if (quoted_line[++i])
				printf(" ");
		}
		if (ft_strncmp(quoted_line[1], "-n\0", 2))
			printf("\n");
	}
	else
		printf("\n");
	free_lines(quoted_line);
	return (1); //o original retorna 0 em sucesso
}
