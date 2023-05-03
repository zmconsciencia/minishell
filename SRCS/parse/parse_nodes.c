/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:42:40 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/03 09:41:23 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_heredoc(char *token)
{
	int	i;

	i = 0;
	if (token[i] == '<' && token[++i] == '<')
		return (1);
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
		fill_red(ft_strjoin((char *)operator, tab[i++]), node_id);
	free_lines(tab);
}

int	is_ready(char *token)
{
	if (token[0] == '<' || token[0] == '>')
		return (1);
	return (0);
}

void	parse_nodes(char **tokens, int node_id)
{
	int	i;
	int	j;

	i = -1;
	while (tokens[++i])
	{
		j = 0;
		if (has_redirect(tokens[i]))
		{
			// if (is_heredoc(tokens[i]))
			// 	// is_readydoc
			// 		// fillheredoc
			// 	else
			// 		// fillheredoc2
			else if (is_ready(tokens[i]))
				fill_red(tokens[i], node_id);
			else
				fill_red2(tokens[i], node_id);
		}
		if (tokens[i][j] == '$')
			fill_dollar(tokens[i], node_id);
		if (tokens[i][j] == '-') // nao é bem assim
			// preenche flags
		else
			// fill_pot()
	}
}