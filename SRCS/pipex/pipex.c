/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:01:46 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/23 13:44:00 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	do_this(t_program *curr)
{
	before_exec(curr);
	if ((execve(curr->pot.path_program, curr->pot.flags, \
		meta()->envp) == -1))
		after_exec(curr);
	free_lines(meta()->envp);
}

void	do_that(t_program *curr)
{
	if (curr->red.fd_in == -1 || curr->red.fd_out == -1)
		exit(1);
	do_builtin(curr);
	free_lines(meta()->envp);
	clear_last();
	exit(0);
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
			do_this(curr);
		else
			do_that(curr);
	}
	if (curr->next && !curr->next->red.fd_in)
		curr->next->red.fd_in = dup(curr->red.fd[0]);
	close_all(curr, 0, 0);
}
