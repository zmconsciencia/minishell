/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_red.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:50:09 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/03 07:21:11 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*retrieve_word(char *token)
{
	int	i;

	i = 0;
	while (token[i])
		i++;
	while (token[i] != '<' || token[i] != '>')
		i--;
}

int	is_heredoc(char *token)
{
	int	i;

	i = 0;
	if (token[i] == '<' && token[++i] == '<')
		return (1);
	return (0);
}

int	is_alone(char *token)
{
	int	i;

	i = 0;
	if (token[i] == '<' || token[i] == '>')
		if (!token[++i])
			return (1);
	return (0);
}

void	fill_red(char *token, char *nxt_token, int id)
{
	t_program	*curr;
	int			i;

	i = 0;
	curr = get_curr_prog(id);
	if (is_alone(token))
	{
		curr->red.operator = token;
		curr->red.file_name = nxt_token;
	}
	else if (is_heredoc(token))
	{
		curr->red.operator = "<<";
		curr->red.file_name = retrieve_word(token);
	}
	else
	{
		curr->red.operator = get_operator(token);
		curr->red.file_name = retrieve_word(token);
	}
}
