/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:09:55 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/30 11:45:08 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_echo(t_program *curr)
{
	int	i;

	i = 1;
	if (curr->pot.flags[i])
	{
		if (!ft_strncmp(curr->pot.flags[i], "-n\0", 2))
			i = 2;
		while (curr->pot.flags[i])
		{
			ft_putstr_fd(curr->pot.flags[i], curr->red.fd_out);
			if (curr->pot.flags[++i])
				ft_putstr_fd(" ", curr->red.fd_out);
		}
		if (ft_strncmp(curr->pot.flags[1], "-n\0", 2))
			ft_putstr_fd("\n", curr->red.fd_out);
	}
	else
		ft_putstr_fd("\n", curr->red.fd_out);
	return (1); //o original retorna 0 em sucesso
}
