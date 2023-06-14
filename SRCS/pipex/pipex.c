/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:01:46 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/14 14:43:21 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	close_all(t_program *curr)
{
	if (curr->red.fd[0] > 2)
		close(curr->red.fd[0]);
	if (curr->red.fd[0] > 2)
		close(curr->red.fd[1]);
	if (curr->red.fd_in > 2)
		close(curr->red.fd_in);
	if (curr->red.fd_out > 2)
		close(curr->red.fd_out);
}

void	do_child(t_program *curr)
{
	if (curr->red.fd_in)
		dup2(curr->red.fd_in, 0);
	if (curr->red.fd_out)
		dup2(curr->red.fd_out, 1);
	else if (curr->next)
		dup2(curr->red.fd[1], 1);
	close_all(curr);
}

void	before_exec(t_program *curr)
{
	struct stat	st;

	if (lstat(curr->pot.path_program, &st) && \
		ft_strncmp("./", curr->pot.path_program, 2 && \
			curr->pot.path_program[0] != '/'))
	{
		perror("");
		close_all(curr);
		exit(127);
	}
	if (S_ISDIR(st.st_mode) && (curr->pot.path_program[0] == '/' || \
		!ft_strncmp("./", curr->pot.path_program, 2)) && \
			!access(curr->pot.path_program, F_OK))
	{
		perror("");
		close_all(curr);
		exit(126);
	}
	if (curr->red.fd_in == -1 || curr->red.fd_out == -1)
	{
		close_all(curr);
		exit(1);
	}
}

void	after_exec(t_program *curr)
{
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
	exit(127);
}

void	pipex(t_program *program)
{
	t_program	*curr;
	int			pid;

	curr = program;
	if (pipe(curr->red.fd) == -1)
		perror ("Pipe error");
	pid = fork();
	if (pid == -1)
		perror ("Fork error");
	if (pid == 0)
	{
		do_child(curr);
		if (!check_builtin(curr))
		{	
			before_exec(curr);
			if ((execve(curr->pot.path_program, curr->pot.flags, \
				meta()->envp) == -1))
				after_exec(curr);
		}
		else
		{
			if (curr->red.fd_in == -1 || curr->red.fd_out == -1)
				exit(1);
			do_builtin(curr);
			exit(0);
		}
	}
	if (curr->next && !curr->next->red.fd_in)
		curr->next->red.fd_in = dup(curr->red.fd[0]);
	close_all(curr);
}

// fprintf(stderr, "%d %d\n", curr->red.fd[0], curr->red.fd[1]);