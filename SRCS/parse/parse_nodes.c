/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:42:40 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/04 11:53:19 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parse_nodes(char **tokens, int id)
{
	int	i;

	i = -1;
	while (tokens[++i])
	{
		if (has_redirect(tokens[i]))
			treat_redirect(tokens[i], id); //ze
		else if (has_quotes(tokens[i])) //ze
		{
			if (!has_dollar(tokens[i]))
				fill_pot(treat_quotes(tokens[i], 1), id); //bruno
			else
				fill_pot(treat_quotes(tokens[i], 2), id); //bruno
		}
		else if (has_dollar(tokens[i]))
			fill_pot(expanded_dollar(tokens), id); //bruno
		else
			fill_pot(tokens[i], id);
	}
}
