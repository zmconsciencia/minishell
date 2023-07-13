/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_red.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:47:58 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/13 16:16:39 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	process_hc(t_program *node, char **tokens, char *op, char *file_name)
{
	int	fd[2];
	int	pid;
	int	status;

	meta()->hc = 1;
	if (pipe(fd) == -1)
		perror("");
	pid = fork();
	if (!pid)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, sighandlerhc);
		run_heredoc(file_name, node, fd);
		free_lines(meta()->nodes);
		free_lines(meta()->envp);
		free_lines(tokens);
		free(meta()->treated);
		free_lines(node->pot.flags);
		free(node);
		free(file_name);
		free(op);
		exit(0);
	}
	else
	{
		close(fd[1]);
		waitpid(0, &status, 0);
		node->red.fd_in = fd[0];
		signal(SIGINT, sighandler);
		signal(SIGQUIT, sighandlerquit);
	}
}

void	fill_red(char *token, t_program *node, char **tokens)
{
	char	*file_name;
	char	*no_quotes;
	char	*op;

	file_name = get_filename(token);
	if (file_name[0] == '\"')
	{
		no_quotes = treat_quotes(file_name);
		free(file_name);
		file_name = no_quotes;
	}
	op = get_op(token);
	if (ft_strlen(op) == 1)
	{
		if (op[0] == 5)
			treat_infiles(file_name, node);
		else
			treat_outfiles(file_name, node);
	}
	else if (ft_strlen(op) == 2)
	{
		if (op[0] == 5)
			process_hc(node, tokens, op, file_name);
		else
			treat_append(file_name, node);
	}
	free(file_name);
	free(op);
}
