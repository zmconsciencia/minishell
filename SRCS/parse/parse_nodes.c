/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:42:40 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/03 19:34:09 by jabecass         ###   ########.fr       */
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
// 			treat_redirect(tokens[i], node_id);
// 		if (tokens[i][j] == '$')
// 			fill_dollar(tokens[i], node_id);
// 		else
// 			fill_pot(tokens[i], node_id);
// 	}
// }
