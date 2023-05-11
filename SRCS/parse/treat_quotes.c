/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:29:42 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/11 14:20:34 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*remove_quotes(char	*token, char c)
{
	int		i;
	int		j;
	int		x;
	char	*unquoted;

	i = -1;
	x = 0;
	while (token[++i])
		if (token[i] == c)
			x++;
	unquoted = malloc(sizeof(char) * (i - x) + 1);
	i = 0;
	j = -1;
	while (token[++j])
		if (token[j] != c)
			unquoted[i++] = token[j];
	unquoted[i] = 0;
	return (unquoted);
}

char	*treat_quotes(char *token)
{
	int		i;
	char	*no_quotes;

	i = -1;
	no_quotes = 0;
	while (token[++i] != '\"' && token[i] != '\'')
		;
	if (token[i] == '\"')
		no_quotes = remove_quotes(token, '\"');
	else if (token[i] == '\'')
		no_quotes = remove_quotes(token, '\'');
	return (no_quotes);
}
