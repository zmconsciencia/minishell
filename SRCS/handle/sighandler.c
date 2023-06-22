/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:02:42 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/22 17:14:03 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sighandler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		if (meta()->exec)
			return ;
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	if (signum == SIGQUIT)
	{
		if (meta()->exec)
			ft_putstr_fd("Quit (core dumped)\n", 2);
		else
			SIG_DFL;
	}
}
