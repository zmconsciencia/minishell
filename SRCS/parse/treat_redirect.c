/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:02:36 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/03 19:33:17 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_append(char *token)
{
	int	i;

	i = 0;
	while (token[i])
		if (token[i] == '>' && token[++i] == '>')
			return (1);
	return (0);
}

int	is_heredoc(char *token)
{
	int	i;

	i = 0;
	while (token[i])
		if (token[i] == '<' && token[++i] == '<')
			return (1);
	return (0);
}

// void	fill_red2(char *token, int node_id)
// {
// 	char		**tab;
// 	char		operator;
// 	int			i;

// 	i = 0;
// 	operator = get_operator(token);
// 	tab = ft_split(token, operator);
// 	fill_pot(tab[0], node_id);
// 	while (tab[i])
// 		fill_red(new_strjoin(operator, tab[i++]), node_id);
// 	free_lines(tab);
// }

int	is_ready(char *token)
{
	if (token[0] == '<' || token[0] == '>')
		return (1);
	return (0);
}

// void	treat_redirect(char *token, int node_id)
// {
// 	if (is_heredoc(token))
// 	{
// 		if (is_ready(token))
// 			// fillheredoc
// 		// else
// 			// fillheredoc2
// 	}
// 	if (is_append(token))
// 	{
// 		if (is_ready(token))
// 			// fillappend
// 		// else
// 			// fillappend2
// 	}
// 	else if (is_ready(token))
// 		fill_red(token, node_id);
// 	else
// 		fill_red2(token, node_id);
// }
