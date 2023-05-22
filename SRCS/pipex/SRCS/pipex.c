/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:01:46 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/22 14:55:45 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	do_child(t_program *curr)
{
	set_fd(curr);
	dup2(curr->red.fd[0], 0);
	close(curr->red.fd[0]);
	dup2(curr->red.fd[1], 1);
	close(curr->red.fd[1]);
}

void	pipex(t_program *program)
{
	t_program	*curr;
	int			pid;

	curr = program;
	while (curr)
	{
		if (pipe(curr->red.fd) == -1)
			perror ("Pipe error");
		pid = fork();
		if (pid == -1)
			perror ("Fork error");
		if (pid == 0)
		{
			do_child(curr);
			if (execve(curr->pot.program, curr->pot.flags, meta()->envp) == -1)
				perror("Could not execute\n");
		}
		close(curr->red.fd[1]);
		curr = curr->next;
	}
	waitpid(-1, NULL, WNOHANG);
}

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
