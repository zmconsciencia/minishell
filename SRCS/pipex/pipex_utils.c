/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:15:12 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/13 13:15:28 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	close_all(t_program *curr, int flag, int exitcode)
{
	if (curr->red.fd[0] > 2)
		close(curr->red.fd[0]);
	if (curr->red.fd[0] > 2)
		close(curr->red.fd[1]);
	if (curr->red.fd_in > 2)
		close(curr->red.fd_in);
	if (curr->red.fd_out > 2)
		close(curr->red.fd_out);
	if (flag == 1)
	{
		clear_last();
		free_lines(meta()->envp);
		if (exitcode)
			exit(exitcode);
	}
}

void	do_child(t_program *curr)
{
	if (curr->red.fd_in)
		dup2(curr->red.fd_in, 0);
	if (curr->red.fd_out)
		dup2(curr->red.fd_out, 1);
	else if (curr->next)
		dup2(curr->red.fd[1], 1);
	close_all(curr, 0, 0);
}

void	before_exec(t_program *curr)
{
	struct stat	st;

	if (!ft_strlen(curr->pot.program))
		close_all(curr, 1, 0);
	if (lstat(curr->pot.path_program, &st) && \
		ft_strncmp("./", curr->pot.path_program, 2 && \
			curr->pot.path_program[0] != '/'))
	{
		perror("");
		close_all(curr, 1, 127);
	}
	if (S_ISDIR(st.st_mode) && (curr->pot.path_program[0] == '/' || \
		!ft_strncmp("./", curr->pot.path_program, 2)) && \
			!access(curr->pot.path_program, F_OK))
	{
		perror("");
		close_all(curr, 1, 126);
	}
	if (curr->red.fd_in == -1 || curr->red.fd_out == -1)
		close_all(curr, 1, 1);
}

void	after_exec(t_program *curr)
{
	free_lines(meta()->envp);
	if (errno == EACCES)
	{
		if (access(curr->pot.flags[0], X_OK) && \
			!ft_strncmp("./", curr->pot.flags[0], 2))
		{
			perror(curr->pot.flags[0]);
			exit(126);
		}
		perror(curr->pot.flags[0]);
		exit(127);
	}
	perror(curr->pot.flags[0]);
	clear_last();
	exit(127);
}
