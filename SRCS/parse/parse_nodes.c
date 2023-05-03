/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:42:40 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/03 06:56:06 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// void	parse_nodes(char **tokens, int node_id)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (tokens[++i])
// 	{
// 		j = 0;
// 		if (has_redirect(tokens[i]))
// 			fill_red(tokens[i], tokens[i + 1], node_id);
// 		if (tokens[i][j] == '$')
// 			fill_dollar(tokens[i], node_id);
// 		if (tokens[i][j] == '-') // nao é bem assim
// 			// preenche flags
// 		else
// 			// fill_pot()
// 	}
// }