/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:44:57 by jabecass          #+#    #+#             */
/*   Updated: 2023/05/18 22:31:32 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	run_heredoc(char *file_name, t_program *node)
{
	char	*str;
	char	*limiter;
	int		here_fds[2];

	(void)node;
	limiter = ft_strjoin(file_name, "\n");
	if (pipe(here_fds) == -1)
		perror("");
	while (1)
	{
		ft_putstr_fd("> ", 1);
		str = get_next_line(0);
		if (!str)
			break ;
		if (!ft_strncmp(str, limiter, ft_strlen(limiter)))
			break ;
		if (str)
		{
			ft_putstr_fd(str, here_fds[1]);
			free(str);
		}
	}
	if (str)
		free(str);
	node->red.fd_in = here_fds[0];
}