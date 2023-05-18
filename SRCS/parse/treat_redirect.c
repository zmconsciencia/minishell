/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:02:36 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/18 21:22:05 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	desired_len(char *str, char op)
{
	int	i;

	i = 0;
	while (str[i] == op || ft_is_space(str[i]))
		i++;
	return (ft_strlen(str) - i);
}

char	*get_filename(char *token)
{
	char	*file_name;
	int		i;
	int		j;

	i = 1;
	j = 0;
	file_name = malloc(sizeof(char) * desired_len(token, token[0]) + 1);
	while (ft_is_space(token[i]) || token[i] == token[0])
		i++;
	while ((token[i] != '\0') || ft_is_space(token[i]))
		file_name[j++] = token[i++];
	file_name[j] = '\0';
	return (file_name); //malloc
}

char	*get_op(char *token)
{
	int		i;
	int		j;
	char	*op;

	i = 1;
	j = 0;
	while (token[i] == token[0])
		i++;
	op = malloc(sizeof(char) * i + 1);
	while (j < i)
	{
		op[j] = token[0];
		j++;
	}
	op[j] = '\0';
	return (op);
}

void	treat_infiles(char *file_name, t_program *node)
{
	node->red.fd_in = open(file_name, O_RDONLY);
	if (node->red.fd_in == -1)
		printf("INFILE: no such file or directory\n");
	else
		printf("INFILE: %s\n", file_name);
	close(node->red.fd_in); // o fd_in e fd_out ficou com o mesmo valor !
}

void	treat_outfiles(char *file_name, t_program *node)
{
	node->red.fd_out = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (node->red.fd_out == -1)
		perror(file_name);
	else
		printf("OUTFILE: %s\n", file_name);
	close(node->red.fd_out);
}

int	treat_heredoc(char *file_name, t_program *node)
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

void	treat_append(char *file_name, t_program *node)
{
	node->red.fd_out = open(file_name, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (node->red.fd_out == -1)
		perror(file_name);
	else
		printf("OUTFILE: %s\n", file_name);
	close(node->red.fd_out);
}

void	treat_redirect(char *token, t_program *node)
{
	char	*file_name;
	char	*op;
	int		fd;

	file_name = get_filename(token);
	op = get_op(token);
	if (ft_strlen(op) == 1)
	{
		if (ft_strncmp(op, "<", 1) == 0)
			treat_infiles(file_name, node);
		else
			treat_outfiles(file_name, node);
	}
	else if (ft_strlen(op) == 2)
	{
		if (ft_strncmp(op, "<", 1) == 0)
			fd = treat_heredoc(file_name, node);
		else
			treat_append(file_name, node);
	}
	free(op);
	free(file_name);
}
