/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:02:42 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/04 14:24:56 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sighandlerquit(int signum)
{
	if (!meta()->hc)
	{
		if (signum == SIGQUIT && meta()->exec)
		{
			ft_putstr_fd("Quit (core dumped)\n", 2);
			meta()->exitcode = 131;
			return ;
		}
		else if (signum == SIGQUIT && !meta()->exec)
			SIG_IGN ;
	}
}

void	sighandler(int signum)
{
	if (!meta()->hc)
	{
		meta()->exitcode = 130;
		if (signum == SIGINT)
		{
			ft_putstr_fd("^C\n", 2);
			if (meta()->exec)
				return ;
			rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
		}
	}
}

void	sighandlerhc(int signum)
{
	if (meta()->hc)
	{
		if (signum == SIGINT)
		{
			ft_putstr_fd("^C\n", 2);
			exit(1);
		}
		if (signum == SIGQUIT)
			SIG_IGN ;
	}
}