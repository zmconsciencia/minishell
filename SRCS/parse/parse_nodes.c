/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:42:40 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/04 10:09:30 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parse_nodes(char **tokens, int node_id)
{
	int	i;

	i = -1;
	while (tokens[++i])
	{
		if (has_redirect(tokens[i]))
			treat_redirect(tokens[i], node_id);
		// if (has_dollar())
		// 	fill_dollar(tokens[i], node_id);
		// else
		// 	fill_pot(tokens[i], node_id);
	}
}
