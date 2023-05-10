/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:42:40 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/10 10:31:58 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
	int			i;
	t_program	*node;

	i = -1;
	node = malloc(sizeof(t_program));
	node->program_id = id;
	while (tokens[++i])
	{
		if (ft_strchr(tokens[i], '>') || ft_strchr(tokens[i], '<')) //bruno -> ><
			treat_redirect(tokens[i], id); //ze
		else if (ft_strchr(tokens[i], '\"') || ft_strchr(tokens[i], '\''))
		{
			if (!ft_strchr(tokens[i], '$'))
				fill_pot(treat_quotes(tokens[i], 1), id); //bruno
			else
				fill_pot(treat_quotes(tokens[i], 2), id); //bruno
		}
		else if (has_dollar(tokens[i]))
			fill_pot(expanded_dollar(tokens[i]), id); //bruno
		else
			fill_pot(tokens[i], id);
	}
	add_to_list(node);
}

//ter atencao caso haja dollar dentro de aspas

//tratar EOF e appe <<>>
//se tiver $ a meio do token, e fazer string join com var expandida

//