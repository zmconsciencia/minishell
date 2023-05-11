/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:42:40 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/11 14:21:52 by bde-seic         ###   ########.fr       */
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
	// t_program	*node;

	(void)id;
	i = -1;
	// node = malloc(sizeof(t_program));
	// node->program_id = id;
	while (tokens[++i])
	{
		// if (ft_strchr(tokens[i], '>') || ft_strchr(tokens[i], '<'))
		// 	treat_redirect(tokens[i], node);
		/* else */ if (ft_strchr(tokens[i], '\"') || ft_strchr(tokens[i], '\''))
						tokens[i] = treat_quotes(tokens[i]);
			// fill_pot(treat_quotes(tokens[i]), node);
		// else
		// 	fill_pot(tokens[i], node);
		printf("%s\n", tokens[i]);
	}
	// add_to_list(node);
	//fazer free token list (**), e fazer free de cada token dentro do fill pot ou fill red
} 

//tratar EOF e appe <<>>
