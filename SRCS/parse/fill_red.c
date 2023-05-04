/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_red.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:50:09 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/04 11:06:22 by bde-seic         ###   ########.fr       */
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

void	handle_infiles(char **tab, int node_id)
{
	int			i;
	t_program	*curr;


	i = 0;
	curr = get_curr_prog(node_id);
	while (tab[i])
	{
		if (curr->red.fd_in)
			close(curr->red.fd_in);
		curr->red.fd_in = open(tab[i], O_RDONLY);
		i++;
	}
	if (curr->red.fd_in == -1)
	{
		perror(tab[i]);
		// curr->red.fd_in = open("tmp", O_CREAT, 0644);
		// program()->tmp_infiles++;
	}
}

void	handle_outfiles(char **tab, int node_id)
{
	int			i;
	t_program	*curr;

	i = 0;
	curr = get_curr_prog(node_id);
	while (tab[i])
	{
		if (curr->red.fd_out)
			close(curr->red.fd_out);
		curr->red.fd_out = open(tab[i], O_CREAT | O_RDWR | O_TRUNC, 0644);
		i++;
	}
	if (curr->red.fd_out == -1)
		perror(tab[i]);
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
	if (count_op_type(token))
	{
		infiles = ft_split(token, '<');
		handle_infiles(infiles, id);
		outfiles = ft_split(token, '>');
		handle_outfiles(outfiles, id);
	}
	else
	{	
		if (token[0] == '<')
		{
			infiles = ft_split(token, '<');
			handle_infiles(infiles, id);
		}
		else if (token[0] == '>')
		{
			outfiles = ft_split(token, '>');
			handle_outfiles(outfiles, id);
		}
	}
}
