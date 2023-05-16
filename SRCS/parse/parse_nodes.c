/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:42:40 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/16 14:49:09 by jabecass         ###   ########.fr       */
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

	(void)id;
	i = -1;
	node = malloc(sizeof(t_program));
	node->program_id = id;
	while (tokens[++i])
	{
		if (ft_strchr(tokens[i], '>') || ft_strchr(tokens[i], '<'))
			treat_redirect(tokens[i], node);
		if (ft_strchr(tokens[i], '\"') || ft_strchr(tokens[i], '\''))
			tokens[i] = treat_quotes(tokens[i]);
			// fill_pot(treat_quotes(tokens[i]), node);
		// else
		// 	fill_pot(tokens[i], node);
	}
	// add_to_list(node);
	//fazer free token list (**), e fazer free de cada token dentro do fill pot ou fill red
} 

//tratar EOF e appe <<>>
