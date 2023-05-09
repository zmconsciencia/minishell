/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:02:36 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/09 13:48:46 by jabecass         ###   ########.fr       */
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

void	treat_infiles(char *file_name, int node_id)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	(void)node_id;
	if (fd == -1)
		printf("INFILE: no such file or directory\n");
	else
		printf("INFILE: %s\n", file_name);
	close(fd);
}

void	treat_outfiles(char *file_name)
{
	int	fd;

	fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		perror(file_name);
	else
		printf("OUTFILE: %s\n", file_name);
	close(fd);
}

void	treat_heredoc(char *file_name)
{
	printf("EOF: %s\n", file_name);
}

void	treat_append(char *file_name)
{
	printf("APPEND: %s\n", file_name);
}

void	fill_red(char *token, int id)
{
	char	*file_name;
	char	*op;

	(void)id;
	file_name = get_filename(token);
	op = get_op(token);
	if (ft_strlen(op) == 1)
	{
		if (ft_strncmp(op, "<", 1) == 0)
			treat_infiles(file_name, id);
		else
			treat_outfiles(file_name);
	}
	else if (ft_strlen(op) == 2)
	{
		if (ft_strncmp(op, "<", 1) == 0)
			treat_heredoc(file_name);
		else
			treat_append(file_name);
	}
	free(token);
	free(op);
	free(file_name);
}
