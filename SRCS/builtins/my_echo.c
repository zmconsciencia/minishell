/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:09:55 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/01 15:28:35 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_echo(t_program *curr)
{
	int	i;

	i = 1;
	if (curr->pot.flags[i])
	{
		if (flag_parse(curr->pot.flags[1], 'n'))
			i = 2;
		while (curr->pot.flags[i])
		{
			ft_putstr_fd(curr->pot.flags[i], curr->red.fd_out);
			if (curr->pot.flags[++i])
				ft_putstr_fd(" ", curr->red.fd_out);
		}
		if (!flag_parse(curr->pot.flags[1], 'n'))
			ft_putstr_fd("\n", curr->red.fd_out);
	}
	else
		ft_putstr_fd("\n", curr->red.fd_out);
	return (1);
}
