/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:01:46 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/13 14:10:15 by jabecass         ###   ########.fr       */
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
		if (curr->red.fd_in == -1)
			exit(1);
		if ((execve(curr->pot.path_program, curr->pot.flags, meta()->envp) == -1) && !check_builtin(curr))
		{
			meta()->exitcode = 127;
			perror(curr->pot.program);
			exit(meta()->exitcode);
		}
		else if (check_builtin(curr))
		{
			do_builtin(curr);
			exit(0);
		}
	}
	if (curr->next && !curr->next->red.fd_in)
		curr->next->red.fd_in = dup(curr->red.fd[0]);
	close_all(curr);
}

// fprintf(stderr, "%d %d\n", curr->red.fd[0], curr->red.fd[1]);