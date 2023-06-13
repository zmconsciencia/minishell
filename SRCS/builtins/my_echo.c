/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:09:55 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/13 16:39:16 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_echo(t_program *curr)
{
	int	i;
	int	fd;

	i = 1;
	fd = 1;
	if (curr->red.fd_out)
		fd = curr->red.fd_out;
	// else if (curr->red.fd[1])
	// 	fd = curr->red.fd[1];
	if (curr->pot.flags[i])
	{
		if (flag_parse(curr->pot.flags[1], 'n'))
			i = 2;
		while (curr->pot.flags[i])
		{
			// printf("%p\n", curr->pot.flags[i]);
			// i++;
			ft_putstr_fd(curr->pot.flags[i], fd);
			if (curr->pot.flags[++i])
				ft_putstr_fd(" ", fd);
		}
		if (!flag_parse(curr->pot.flags[1], 'n'))
			ft_putstr_fd("\n", fd);
	}
	else
		ft_putstr_fd("\n", fd);
	return (1);
}
