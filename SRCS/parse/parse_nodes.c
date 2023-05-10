/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:42:40 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/10 13:11:30 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*join_dollar(char *token) //ver qual a primeira
{
	int		i;
	char	**split;
	char	*joined;

	i = -1;
	split = ft_split(token, '$');
	if (token[0] == '$')
		joined = split[0];
	else
		joined = expanded_dollar(split[0]);
	while (split[++i])
		joined = ft_strjoin(joined, expanded_dollar(split[i]));
	free(token);
	while (split[i] != 0)
		free(split[i--]);
	free(split);
	return (joined);
}

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
	i = -1;
	j = -1;
	while (token[++j] != c)
	// if xonruinw
		unquoted[++i] = token[j];
	unquoted[i] = 0;
	free(token);
	return (unquoted);
}

char	*treat_quotes(char *token)
{
	int		i;
	char	*no_quotes;

	i = -1;
	no_quotes = 0;
	while (token[++i] != '\"' || token[i] != '\'')
		;
	if (token[i] == '\"')
		no_quotes = remove_quotes(token, '\"');
	else if (token[i] == '\"')
		no_quotes = remove_quotes(token, '\'');
	return (no_quotes);
}

void	add_to_list(t_program *node)
{
	t_program	*curr;

	curr = meta()->head;
	while (curr->next != 0)
		curr = curr->next;
	curr->next = node;
	if (!curr->next)
		meta()->tail = node;
}

// A FUNCAO EXPANDED_DOLLAR RETORNA UM MALLOC, QUE VAI PRECISAR SER FREED
void	parse_nodes(char **tokens, int id)
{
	(void)id;
	int			i;
	// t_program	*node;

	i = -1;
	// node = malloc(sizeof(t_program));
	// node->program_id = id;
	while (tokens[++i])
	{
		printf("%s\n", tokens[i]);
	// 	if (ft_strchr(tokens[i], '>') || ft_strchr(tokens[i], '<'))
	// 		treat_redirect(tokens[i], node);
	// 	else if (ft_strchr(tokens[i], '\"') || ft_strchr(tokens[i], '\'')) // pelicas nao levam expansao
	// 		fill_pot(treat_quotes(tokens[i]), node);
	// 	else
	// 		fill_pot(tokens[i], node);
	}
	// add_to_list(node);
	//fazer free token list (**), e fazer free de cada token dentro do fill pot ou fill red
} 

//ter atencao caso haja dollar dentro de aspas

//tratar EOF e appe <<>>
//se tiver $ a meio do token, e fazer string join com var expandida

//