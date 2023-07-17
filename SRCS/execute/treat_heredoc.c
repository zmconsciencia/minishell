/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:44:57 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/17 11:03:10 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	hc_ctrld(char *file_name)
{
	int	i;

	i = 0;
	ft_putstr_fd("minishell: warning: ", 2);
	ft_putstr_fd("here-document delimited ", 2);
	ft_putstr_fd("by end-of-file (wanted `", 2);
	while (file_name[i])
		write(2, &file_name[i++], 1);
	ft_putstr_fd("\')\n", 2);
	return (1);
}

void	run_heredoc(char *file_name, int here_fds[2])
{
	char	*str;
	char	*limiter;

	limiter = ft_strjoin(file_name, "\n");
	while (1 && ft_return_putstr_fd("> ", 1))
	{
		str = get_next_line(0);
		if (!str && hc_ctrld(file_name))
			break ;
		if (!ft_strncmp(str, limiter, ft_strlen(limiter)))
			break ;
		if (str)
		{
			str = expand_now(str, '$');
			ft_putstr_fd(str, here_fds[1]);
			free(str);
		}
	}
	free(limiter);
	if (str)
		free(str);
	close(here_fds[1]);
	close(here_fds[0]);
}
