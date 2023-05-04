/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_red.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:50:09 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/04 10:54:52 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_op_type(char *token)
{
	int		i;
	char	op;

	i = 0;
	op = token[0];
	if (op == '>')
	{	
		while (token[i])
			if (token[i++] == '<')
				return (1);
	}
	else if (op == '<')
	{
		while (token[i])
			if (token[i++] == '>')
				return (1);
	}
	return (0);
}

void	fill_red2(char *token, int node_id)
{
	char		**tab;
	char		operator;
	int			i;

	i = 0;
	operator = get_operator(token);
	tab = ft_split(token, operator);
	fill_pot(tab[0], node_id);
	while (tab[i])
		fill_red(new_strjoin(operator, tab[i++]), node_id);
	free_lines(tab);
}

void	handle_infiles(char **tab)
{
	int	i;
	int	fd;

	i = 0;
	fd = 0;
	while (tab[i])
	{
		if (fd)
			close(fd);
		fd = open(tab[i], O_RDONLY);
		i++;
	}
	if (fd == -1)
	{
		perror(tab);
		fd = open("tmp", O_CREAT, 0644);
		program()->tmp_infiles++;
	}
}

void	handle_outfiles(char **tab)
{
	int	i;
	int	fd;

	i = 0;
	fd = 0;
	while (tab[i])
	{
		if (fd)
			close(fd);
		fd = open(tab[i], O_CREAT | O_RDWR | O_TRUNC, 0644);
		i++;
	}
	if (fd == -1)
		perror(tab);
}

void	fill_red(char *token, int id)
{
	t_program	*curr;
	char		operator;
	int			i;
	char		**infiles;
	char		**outfiles;

	i = 0;
	curr = get_curr_prog(id);
	operator = token[0];
	if (count_op_type(token))
	{
		infiles = ft_split(token, '<');
		outfiles = ft_split(token, '>');
	}
	else
	{	
		if (token[0] == '<')
			infiles = ft_split(token, '<');
		else if (token[0] == '>')
			outfiles = ft_split(token, '>');
	}
	if (infiles)
		handle_infiles(infiles);
	if (outfiles)
		handle_outfiles(outfiles);
}
// curr->red.operator = get_operator(token);
// curr->red.file_name = retrieve_word(token);