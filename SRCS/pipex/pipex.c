/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:01:46 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/23 16:28:55 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	do_child(t_program *curr)
{
	// set_fd(curr);
	if (curr->red.fd_in)
		dup2(curr->red.fd_in, 0);
	else
		dup2(curr->red.fd[0], 0);
	if (curr->red.fd_out)
		dup2(curr->red.fd_out, 1);
	else if (curr->next)
		dup2(curr->red.fd[1], 1);
	close(curr->red.fd[0]);
	close(curr->red.fd[1]);
	if (curr->red.fd_in)
		close(curr->red.fd_in);
	if (curr->red.fd_out)
		close(curr->red.fd_out);
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
		if (execve(curr->pot.program, curr->pot.flags, meta()->envp) == -1)
		{
			perror("Could not execute\n");
			exit(0);
		}
	}
	if (curr->next && !curr->next->red.fd_in)
		curr->next->red.fd_in = dup(curr->red.fd[0]);
	close(curr->red.fd[0]);
	close(curr->red.fd[1]);
}

// fprintf(stderr, "%s %d %d %d %d\n", curr->pot.flags[0],curr->red.fd_in, \
 curr->red.fd_out, curr->red.fd[0], curr->red.fd[1]);

// void	go_function(int argc, char **argv, char **envp)
// {
// 	t_program	*list;
// 	t_program	*curr;
// 	int			pid;

// 	list = 0;
// 	fill_list(&list, argc, argv, envp);
// 	curr = list;
// 	while (curr && curr->i <= argc - 2)
// 	{
// 		if (pipe(curr->fd) == -1)
// 			perror ("Pipe error");
// 		pid = fork();
// 		if (pid == -1)
// 			perror ("Fork error");
// 		if (pid == 0)
// 		{
// 			do_child(curr, list, argc, argv);
// 			if (execve(curr->path, curr->flags, envp) == -1)
// 				perror("Could not execute\n");
// 		}
// 		close(curr->fd[1]);
// 		curr = curr->next;
// 	}
// 	waitpid(-1, NULL, WNOHANG);
// 	free_my_list(list);
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	if (argc >= 5)
// 		go_function(argc, argv, envp);
// 	else
// 		ft_putstr_fd("Invalid number of arguments\n", 2);
// }
