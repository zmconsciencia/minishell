/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:01:46 by bde-seic          #+#    #+#             */
/*   Updated: 2023/04/11 16:53:22 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	do_child(t_program *curr, t_program *list, int argc, char **argv)
{
	set_fd(curr, &list, argc, argv);
	dup2(curr->fd[0], 0);
	close(curr->fd[0]);
	dup2(curr->fd[1], 1);
	close(curr->fd[1]);
}

void	go_function(int argc, char **argv, char **envp)
{
	t_program	*list;
	t_program	*curr;
	int			pid;

	list = 0;
	fill_list(&list, argc, argv, envp);
	curr = list;
	while (curr && curr->i <= argc - 2)
	{
		if (pipe(curr->fd) == -1)
			perror ("Pipe error");
		pid = fork();
		if (pid == -1)
			perror ("Fork error");
		if (pid == 0)
		{
			do_child(curr, list, argc, argv);
			if (execve(curr->path, curr->flags, envp) == -1)
				perror("Could not execute\n");
		}
		close(curr->fd[1]);
		curr = curr->next;
	}
	waitpid(-1, NULL, WNOHANG);
	free_my_list(list);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc >= 5)
		go_function(argc, argv, envp);
	else
		ft_putstr_fd("Invalid number of arguments\n", 2);
}
